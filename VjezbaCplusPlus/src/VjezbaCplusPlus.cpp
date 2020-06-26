#include <iostream>
#include <string>
#include <memory>
#include <GLFW/glfw3.h>
#include <vector>


#define LOG(x) std::cout << x << std:endl;

class Log {
public:
	enum Level 
	{
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel = LevelInfo;
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}
};

class Entity
{
public:
	Entity()
	{
		std::cout << "Kreirano Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destruktno Entity!" << std::endl;
	}

	void Print()
	{
			
	}
};

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		:x(x), y(y), z(z)
	{
	}

	Vertex(const Vertex& vertex)
		:x(x), y(y), z(z)
	{
		std::cout << "Copied!" << std::endl;
	}

	~Vertex()
	{
		//std::cout << "destroyed" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}
	
int main()
{
	int a = glfwInit();
	std::cout << a << std::endl; 

	//{
	//	std::unique_ptr<Entity> entity = std::make_unique<Entity>();
	//	entity->Print();
	//}

	//std::vector<Vertex> vertices;
	//vertices.reserve(3);
	//vertices.emplace_back(1, 2, 3);
	//vertices.emplace_back( 4, 5, 6);
	//vertices.emplace_back(7, 8, 9);

	std::cin.get();
}
