#include "GameMap.h"

GameMap::GameMap()
{
	//int x;
	for (size_t i = 0; i < 10; i++){
		for (size_t j = 0; j < 10; j++){
			layer1[i][j] = new bases::Tile(16 * j, 16 * i, 16, 0, 16, 16, 1, 1);
			layer1[i][j]->setPosition(16 * j, 16 * i);
			//layer1[i][j]->nextFrame();
			//x = layer1[i][j]->getImageX() + layer1[i][j]->getImageWidth()*layer1[i][j]->getMaxFrame()*layer1[i][j]->getAnimSet();
			//layer1[i][j]->setTextureRect(sf::IntRect(x, layer1[i][j]->getImageY(), layer1[i][j]->getImageWidth(), layer1[i][j]->getImageHeight()));
		}
	}

	for (size_t i = 0; i < 10; i++){
		layer1[9][i] = new bases::Tile(16 * i, 160, 0, 0, 16, 16, 1, 1);
		layer1[9][i]->setPosition(16 * i, 16*9);
		//layer1[9][i]->previousFrame();
		//x = layer1[9][i]->getImageX() + layer1[9][i]->getImageWidth()*layer1[9][i]->getMaxFrame()*layer1[9][i]->getAnimSet();
		//layer1[9][i]->setTextureRect(sf::IntRect(x, layer1[9][i]->getImageY(), layer1[9][i]->getImageWidth(), layer1[9][i]->getImageHeight()));
		layer1[9][i]->setType(TileTypes::SOLID);
	}
}

GameMap::GameMap(string filename)
{
	loadMap();
}

GameMap::~GameMap()
{}

//Missing reference to how many tiles there are per line to calculate which tile to select correctly
void GameMap::drawBackground(RenderWindow * window, Texture tileset)
{
	sf::Sprite temp;
	for (size_t i = 0; i < 10; i++){
		for (size_t j = 0; j < 10; j++){
			temp = sf::Sprite(tileset);
			temp.setPosition(layer1[i][j]->getPosition().x, layer1[i][j]->getPosition().y);
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

void GameMap::loadMap()
{
	int tilesetWidth, tilesetHeight;
	int tileSize;
	int tilesPerRow; //=tilesetWidth/tileSize
	string srcImage;
	int firstgid = 0;
	int x = 0, y = 0;
	int curTileId;

	TiXmlDocument doc("demo.tmx");
	doc.LoadFile();

	if (doc.LoadFile())
	{
		TiXmlHandle hDoc(&doc);
		TiXmlElement *pMapRoot, *pTileset, *pImage, *pLayer, *pData, *pTile;
		pMapRoot = doc.FirstChildElement("map");
		if (pMapRoot)
		{
			width = atoi(pMapRoot->Attribute("width"));
			height = atoi(pMapRoot->Attribute("height"));
			tileSize = atoi(pMapRoot->Attribute("tilewidth"));

			pTileset = pMapRoot->FirstChildElement("tileset");
			if (pTileset)
			{
				firstgid = atoi(pMapRoot->Attribute("firstgid"));

				pImage = pTileset->FirstChildElement("image");
				if (pImage)
				{
					tilesetWidth = atoi(pTileset->Attribute("width"));
					tilesetHeight = atoi(pTileset->Attribute("height"));
					srcImage = pTileset->Attribute("source");

					tilesPerRow = tilesetWidth / tileSize;
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
							curTileId = atoi(pTileset->Attribute("gid"))-firstgid;
							int row = curTileId / tilesPerRow;
							int imageX = row*tileSize;


							pTile = pTile->NextSiblingElement();
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
}