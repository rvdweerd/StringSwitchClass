#pragma once
#include <functional>
#include <unordered_map>
#include <string>
#include <iostream>

class StringSwitch
{
public:
	std::function<void()>& Capture(const std::string& str)
	{
		return map[str];
	}
	std::function<void()>& Default()
	{
		return def;
	}
	void operator[](const std::string& str) const
	{
		auto it = map.find(str);
		if (it != map.end())
		{
			it->second();
		}
		else
		{
			def();
		}
	}
private:
	std::unordered_map<std::string, std::function<void()>> map;
	std::function<void()> def = [](){};
};