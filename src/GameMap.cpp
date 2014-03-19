#include "GameMap.h"

GameMap::GameMap()
{
}

GameMap::~GameMap()
{}

sf::Vector2i GameMap::getSize(){
	return sf::Vector2i(width, height);
}
void GameMap::loadDefault()
{
	//int x;
	for (size_t i = 0; i < 10; i++){
		for (size_t j = 0; j < 10; j++){
			layer1[i][j] = new bases::Tile(16 * j, 16 * i, 16, 0, 16, 16, 1, 1,0,0,0);
			layer1[i][j]->setPosition(16 * j, 16 * i);
			//layer1[i][j]->nextFrame();
			//x = layer1[i][j]->getImageX() + layer1[i][j]->getImageWidth()*layer1[i][j]->getMaxFrame()*layer1[i][j]->getAnimSet();
			//layer1[i][j]->setTextureRect(sf::IntRect(x, layer1[i][j]->getImageY(), layer1[i][j]->getImageWidth(), layer1[i][j]->getImageHeight()));
		}
	}

	for (size_t i = 0; i < 10; i++){
		layer1[9][i] = new bases::Tile(16 * i, 160, 0, 0, 16, 16, 1, 1,0,0,0);
		layer1[9][i]->setPosition(16 * i, 16*9);
		//layer1[9][i]->previousFrame();
		//x = layer1[9][i]->getImageX() + layer1[9][i]->getImageWidth()*layer1[9][i]->getMaxFrame()*layer1[9][i]->getAnimSet();
		//layer1[9][i]->setTextureRect(sf::IntRect(x, layer1[9][i]->getImageY(), layer1[9][i]->getImageWidth(), layer1[9][i]->getImageHeight()));
		//layer1[9][i]->setType(TileTypes::SOLID);
	}
}

void GameMap::drawBackground(RenderWindow * window, Texture tileset)
{
	sf::Sprite temp;
	for (size_t i = 0; i < height; i++){
		for (size_t j = 0; j < width; j++){
			temp = sf::Sprite(tileset);
			temp.setPosition(layer1[i][j]->getX(), layer1[i][j]->getY());
			//cout << layer1[i][j]->getImageX() << "////" << layer1[i][j]->getImageY() << endl;
			int x = layer1[i][j]->getImageX() + layer1[i][j]->getImageWidth()*layer1[i][j]->getMaxFrame()*layer1[i][j]->getAnimSet();
			temp.setTextureRect(sf::IntRect(x, layer1[i][j]->getImageY(), layer1[i][j]->getImageWidth(), layer1[i][j]->getImageHeight()));
			window->draw(temp);
		}
	}
}

void GameMap::setId(int id)
{
	this->id = id;
}

int GameMap::getId()
{
	return id;
}

string GameMap::loadMap(string filename)
{
	int tilesetWidth, tilesetHeight;
	int tileSize;
	int tilesPerRow; //=tilesetWidth/tileSize
	string srcImage;
	int firstgid = 0;
	int x = 0, y = 0;
	int curTileId;

	string path = "../assets/";
	path.append(filename);
	path.append(".tmx");
	TiXmlDocument doc(path.c_str());
	doc.LoadFile();

	cout << "Successfully loaded .tmx file." << endl;

	if (doc.LoadFile())
	{
		TiXmlHandle hDoc(&doc);
		TiXmlElement *pMapRoot, *pTileset, *pImage, *pTileProp, *pLayer, *pData, *pTile, *pProperties, *pProperty;
		pMapRoot = doc.FirstChildElement("map");
		if (pMapRoot)
		{
			width = atoi(pMapRoot->Attribute("width"));
			height = atoi(pMapRoot->Attribute("height"));
			tileSize = atoi(pMapRoot->Attribute("tilewidth"));

			pTileset = pMapRoot->FirstChildElement("tileset");
			if (pTileset)
			{
				firstgid = atoi(pTileset->Attribute("firstgid"));

				pImage = pTileset->FirstChildElement("image");
				if (pImage)
				{
					tilesetWidth = atoi(pImage->Attribute("width"));
					tilesetHeight = atoi(pImage->Attribute("height"));
					srcImage = pImage->Attribute("source");
					tilesPerRow = tilesetWidth / tileSize;
					/*if ((layer1 = (bases::Tile * **)malloc(height*sizeof(bases::Tile **))) == NULL)
					{
						perror("Allocating first array of layer 1.\n");
					}
					cout << "Successfully malloc'd." << endl;
					for (int i = 0; i < height; i++)
					{
						if ((layer1[i] = (bases::Tile * *)malloc(width*sizeof(bases::Tile *))) == NULL)
						{
							perror("Allocating second array of layer 1.\n");
						}
					}
					cout << "Successfully malloc'd twice." << endl;*/
					for (size_t i = 0; i < width; i++)
					{
						vector<bases::Tile *> newVector;
						layer1.push_back(newVector);
					}
				}
				pTileProp = pTileset->FirstChildElement("tile");
				int tilePropId = 0;
				if (pTileProp)
				{
					while (pTileProp)
					{
						tilePropId = atoi(pTileProp->Attribute("id"));

						string attribute;
						int value;
						pProperties = pTileProp->FirstChildElement("properties");

						if (pProperties)
						{
							pProperty = pProperties->FirstChildElement("property");
							if (pProperty)
							{
								while (pProperty)
								{
									attribute = pProperty->Attribute("name");
									value = atoi(pProperty->Attribute("value"));

									templateMap.insert({ attribute, value });

									pProperty = pProperty->NextSiblingElement();
								}
							}
						}

						pTileProp = pTileProp->NextSiblingElement();
					}
				}
			}
			pLayer = pMapRoot->FirstChildElement("layer");
			if (pLayer)
			{
				pData = pLayer->FirstChildElement("data");
				if (pData)
				{
					pTile = pData->FirstChildElement("tile");

					if (pTile)
					{
						while (pTile)
						{
							int row = 0;
							int column = 0;
							curTileId = atoi(pTile->Attribute("gid"))- firstgid;
							/*if ((curTileId % tilesPerRow)!=0)
								row = (curTileId / tilesPerRow );
							else
							{
								row = (curTileId / tilesPerRow) - 1;
							}*/
							row = (curTileId / tilesPerRow);
							int imageY = abs(row*tileSize);
							
							int imageX;
							if (curTileId < tilesPerRow)
							{
								imageX = abs(curTileId*tileSize);
							}
							else
							{
								column = curTileId - tilesPerRow*row;
								imageX = abs(column*tileSize);
							}

							layer1[y].push_back(new bases::Tile(x*tileSize, y*tileSize, imageX, imageY, tileSize, tileSize, 1, 1,curTileId, 0,0));
							//cout << x << "////" << y << "/////" << imageX << "////" << imageY << endl;
							pTile = pTile->NextSiblingElement();

							x++;
							if (x > (width-1))
							{
								x = 0;
								y++;
							}

							if (y > (height - 1))
								break;
						}
					}
				}
			}
		}
	}
	else
	{
		perror("Could not load XML File.");
	}

	return srcImage;
}