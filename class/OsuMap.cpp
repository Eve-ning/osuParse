#include "../pch.h"
#include "pch.h"
#include "osuMap.h"

OsuMap::OsuMap(const std::string & filePath)
{
	std::ifstream ts(filePath);
	std::stringstream ss;
	ss << ts.rdbuf();

	std::vector<std::string> mapSettingsVector;
	std::vector<std::string> mapTPVector;
	std::vector<std::string> mapHOVector;

	segmentFile(ss, mapSettingsVector, "[TimingPoints]");
	segmentFile(ss, mapTPVector, "[HitObjects]");
	segmentFile(ss, mapHOVector, "");

	// Map Settings Debug
	MapSettings settings = MapSettings(mapSettingsVector);
	settings.debugSettings();

	// TimingPoint Debug
	std::vector<std::shared_ptr<TimingPoint>> TPList;

	for (const std::string& str : mapTPVector) {
		TPList.push_back(TimingPoint::allocate(str));
	}

	for (const auto TP : TPList) {
		std::cout << TP->str() << std::endl;
	}
	
	// TimingPoint Debug
	std::vector<std::shared_ptr<HitObject>> HOList;

	for (const std::string& str : mapHOVector) {
		HOList.push_back(HitObject::allocate(str, 7));
	}

	for (const auto HO : HOList) {
		std::cout << HO->str() << std::endl;
	}

}

OsuMap::~OsuMap()
{
}

// Takes a stringstream and fills in the vector, breaks on specified tag
// Skips all Tags and Comments
void OsuMap::segmentFile(std::stringstream & ss, std::vector<std::string>& vectorToFill, const std::string & nextTag)
{
	std::string item;

	while (std::getline(ss, item, '\n')) {
		if (item == nextTag) { // If we hit any of the nextTag we break.
			break;
		}

		if (item == "") { // If blank, skip
			continue;
		}
		else if (
			item.front() == '[' || item.back() == ']' || // If tag, we skip
			item.front() == '/') { // If comment, we skip
			continue;
		}
		else
		{
			vectorToFill.push_back(item);
		}
	}
}
