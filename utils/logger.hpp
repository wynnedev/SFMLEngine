//
// Created by 200458668 on 1/31/2022.
//

#ifndef SFML_ENGINE_LOGGER_HPP
#define SFML_ENGINE_LOGGER_HPP

//Singleton Class

#include <string>
#include <iostream>

namespace IE{
  enum PRIORITY{
  INFO,
  TROUBLE,
  ERROR,
  CRITICAL
};
  class Logger {
  public:
    static Logger& Instance() {
      static Logger *instance = new Logger();
      return *instance;
    };

    void SendMessage(PRIORITY priority, std::string message){
      switch(priority){
      case INFO:
        std::cout << "INFO::" << message << std::endl;
        break;
      case TROUBLE:
        std::cout << "TROUBLE::" << message << std::endl;
        break;
      case ERROR:
        std::cout << "ERROR::" << message << std::endl;
        break;
      case CRITICAL:
        std::cout << "CRITICAL::" << message << std::endl;
        break;
      }
    }

  private:
    Logger() = default;

    static Logger *_instance;
  };

};


#endif // SFML_ENGINE_LOGGER_HPP
