#include <fstream>
#include <iostream>
#include <sstream>

#include <urdf/model.h>
#include <urdf_parser/urdf_parser.h>
#include <tinyxml2.h>

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Usage: sdf_to_urdf <input_sdf_file> <output_urdf_file>" << std::endl;
    return 1;
  }
  std::string sdf_file = argv[1];
	std::ifstream file(sdf_file);
	if (!file) {
		std::cerr << "Failed to open SDF file: " << sdf_file << std::endl;
		return 1;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string sdf_str = buffer.str();

	urdf::Model model;
  // This works due to sdformat_urdf
	if (!model.initString(sdf_str)) {
		std::cerr << "Failed to parse SDF file: " << sdf_file << std::endl;
		return 1;
	}
	std::cout << "Successfully loaded SDF model: " << model.getName() << std::endl;

  tinyxml2::XMLDocument* urdf_xml_doc = urdf::exportURDF(model);

  std::string output_file = argv[2];
  tinyxml2::XMLError save_result = urdf_xml_doc->SaveFile(output_file.c_str());
  if (save_result == tinyxml2::XML_SUCCESS) {
    std::cout << "URDF XML saved to: " << output_file << std::endl;
  } else {
    std::cerr << "Failed to save URDF XML to: " << output_file << std::endl;
  }
  return 0;
}
