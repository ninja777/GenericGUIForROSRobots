#include "configurationreader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


ConfigurationReader::ConfigurationReader()
{
    delimiter_ = '=';
    readConfiguration();
}

ConfigurationReader::ConfigurationReader(const char *file_name)
{
    readConfiguration(file_name);
}

void ConfigurationReader::readConfiguration(){
    readConfiguration("config.ini");
}

void ConfigurationReader::readConfiguration(const char *file_name){

    std::string current_line,token;
    std::ifstream config_file(file_name);

    if(config_file.is_open()){
        while(std::getline(config_file,current_line)){
            std::stringstream ss;
            ss<<current_line;
            int counter;
            while(std::getline(ss,token,delimiter_) && counter<2){
                std::cout<<trim(token)<<std::endl;
            }
        }
        config_file.close();
    }
    else
        std::cout<<"Could not read the file"<<std::endl;
}
