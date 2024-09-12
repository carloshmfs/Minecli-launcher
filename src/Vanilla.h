#pragma once

#include <string>

class Vanilla
{
public:
	Vanilla();
	~Vanilla();

private:
	// GAME DIRECTORIES
	std::string m_work_dir;
	std::string m_versions_dir;
	std::string m_assets_dir;
	std::string m_libraries_dir;
	std::string m_jvm_dir;
	std::string m_bin_dir;
};

