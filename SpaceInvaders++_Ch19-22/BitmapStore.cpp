#include "BitmapStore.h"
#include <assert.h>

using namespace sf;
using namespace std;

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore() {
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

void BitmapStore::addBitmap(std::string const& filename) {
	// Get a referance to m_Textures using m_s_Instance
	auto& bitmapsMap = m_s_Instance->m_BitmapsMap;
	// auto is the equivalent of map<string, Texture>
	
	// Create an iterator to hold a key-value-pair (kvp)
	// and search for the required kvp 
	//using the passed in name file
	auto keyValuePair = bitmapsMap.find(filename);
	// auto is the equivelent of map<string, Texture>::iterator

	// No match found so save the texture in the map
	if (keyValuePair == bitmapsMap.end()) {
		// Create a new key value pair using the filename
		auto& texture = bitmapsMap[filename];
		// Load the texture from file
		texture.loadFromFile(filename);
	}
}

sf::Texture& BitmapStore::getBitmap(std::string const& filename) {
	// Get a reference to m_Textures using m_s_Instance
	auto& m = m_s_Instance->m_BitmapsMap;
	// auto is the equivealent of map<string, Texture>

	// Create an iterator to hold a key-value-pair (kvp)
	auto keyValuePair = m.find(filename);
	// auto is the equivealent of map<string, Texture>::iterator

	// Did we find a match?
	if (keyValuePair != m.end()) {
		return keyValuePair->second;
	}
	else {
#ifdef debugginOnConsole
		cout <<
			"BitmapStore::getBitmap()Texture not found"
			<< endl;
#endif
		return keyValuePair->second;
	}
}