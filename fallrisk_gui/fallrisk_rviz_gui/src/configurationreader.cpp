#include "configurationreader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <typeinfo>
#include <string>
ConfigurationReader::ConfigurationReader()
{
    delimiter_ = '=';
    currentTopics = readConfiguration();
}

ConfigurationReader::ConfigurationReader(const char *file_name)
{
    readConfiguration(file_name);
}

std::map<std::string, std::string> ConfigurationReader::readConfiguration(){
    return readConfiguration("config.ini");
}

std::map<std::string, std::string> ConfigurationReader::readConfiguration(const char *file_name){

    std::string current_line,token;
    std::ifstream config_file(file_name);
    std::string topicName;
    std::string topicType;
    std::map<std::string, std::string> topicMap;
    std::string lineString;
    int i;
    if(config_file.is_open()){
        while(std::getline(config_file,current_line)){
            std::stringstream ss;
            ss<<current_line;            
            int counter;
            lineString = ss.str();
            if(lineString.find("//") == std::string::npos){
                lineString.erase(std::remove_if(lineString.begin(), lineString.end()+1, isspace));
                for(i=1; i<lineString.length(); i++){
                    if(lineString[i] == delimiter_){
                        break;
                    }
                }
                topicType = lineString.substr(0, i);
                topicName = lineString.substr(i+1, lineString.length()-i-1);
                std::cout<<topicType<<"\n";
                std::cout<<topicName<<"\n";
                topicMap[topicType] = topicName;
                std::cout<<"Map set completed\n";            
            }
            while(std::getline(ss,token,delimiter_) && counter<2){
                
                std::cout<<trim(token)<<std::endl;
    
            }
        }
        config_file.close();
    }
    else
    {
        std::cout<<"Could not read the file"<<std::endl;
    }
    return topicMap;
}

/*
int main(int argc, char **argv)
{
  ConfigurationReader reader;//=ConfigurationReader();
  std::cout<<reader.currentTopics.size()<<"\n";
  return 1;
}
*/
