#pragma once

#include <exception>
#include <string>
#include <cstring>
#include "ArgList.hh"
#include "ArgParserCommons.hh"

namespace HLSLBuilder
{
	/**
	* A class to convert the string cmd args to proper args.
	*/
	class HLSLB_API ArgParser
	{
	public:
		/**
		* Receives the arg list and parse then to proper enums and filter the file input
		*/
		static void SetControlArgs(const std::list<std::pair<HLSLBuilder::ArgCategory, std::string>>& controlArgs);
		/**
		* Return all build infos
		*/
		static BuildInfos GetBuildInfos();
	private:
		static void CastMapToBuildInfos(std::unordered_map<HLSLBuilder::ArgCategory, std::string>& mappedArgs);
		static void ValidateFileExtension(std::string_view path);
		static void FindFile(std::string_view path);
		static BuildMode CastStringToBuildMode(std::string strValue);
		static OutputTarget CastStringToOutputTarget(std::string strValue);
		static BuildInfos s_BuildInfos;
	};
}