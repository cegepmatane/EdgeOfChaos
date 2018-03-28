#include <pugixml.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <sstream>
#include <iostream>

struct xml_string_writer: pugi::xml_writer
{
	std::string result;

	virtual void write(const void* data, size_t size)
	{
		result.append(static_cast<const char*>(data), size);
	}
};

int main(void)
{
	pugi::xml_document doc;
	pugi::xml_node ip = doc.append_child("test").append_child("reseau").append_child("adresse");;
	pugi::xml_node machine = doc.child("test").child("reseau").append_child("machine");
	machine.text().set("Debian");
	ip.append_attribute("ip").set_value("localhost");
	std::stringstream test;
	if(ip)
	{
		doc.print(test);
		std::cout << test.str() << std::endl;
	}
	std::string reseau = test.str();
	pugi::xml_document aze;
	pugi::xml_parse_result tst = aze.load_string(reseau.c_str());
	std::cout << aze.child("test").child("reseau").child("machine").child_value() << std::endl;
	std::cout << aze.child("test").child("reseau").child("adresse").attribute("ip").value() << std::endl;


	return 0;
}

// g++ -g main.cpp -o exec.exe -L/usr/include -lpugixml
