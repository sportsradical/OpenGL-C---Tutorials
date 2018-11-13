#pragma once
#include <iostream>
#include<fstream>
#include<vector>
#include <string>


#include <SOIL2/SOIL2.h>

#include <GL/glew.h>
#include <glfw3.h>

#include<glm.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc/type_ptr.hpp>


using namespace std;

class CShader
{
public:
	CShader();
	CShader(const char* vertextFile, const char* fragmentFile);
	CShader(const char* vertextFile, const char* geometryFile, const char* fragmentFile);
	virtual ~CShader();

	string LoadFileName(const char* filename);
	GLuint LoadShader(GLenum type, const char* fileName);
	void LinkToPrograma(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader);
	
	GLuint CreateProgram();
	bool AttachShader(GLuint id, GLuint shader);
	void LinKPrograma(GLuint id);
	void UsePrograma();
	void UnUsed();
	void GetProgramiv (GLuint program, GLenum pname, GLint& param);
	void GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
	void GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
	void GetShaderiv(GLuint shader, GLenum pname, GLint* param);
	void CompileShader(GLuint shader);
	void ShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint* length);
	GLuint CreateShader(GLenum shaderType);
	void DeleteShader(GLuint shader);
	void DeleteProgram(GLuint id);
protected:
	// programa
	GLuint id;
	GLuint m_vertex;
	const char* vertextFile;
	const char* fragmentFile;
	const char* geometryFile;
	GLuint vertexShader;
	GLuint fragShader;
	GLuint geometryShader;
	GLuint m_shader;
};
