#include "debugstream.h"


#include <windows.h>


//namespace debug {

	bool debugstream::m_bool_alpha{ true };
	bool debugstream::m_auto_new_line{ true };
	bool debugstream::m_auto_delimiter{ false };
	std::string debugstream::m_delimiter(" ");
	bool debugstream::m_except_mode_activated{ false };

	debugstream& debug() {
		static debugstream singletonDebugStream;
		return singletonDebugStream;
	}

	debugstream& debugstream::operator<<(std::string str)
	{
		if (str != "\n") {
			if (debugstream::m_auto_delimiter) str += debugstream::m_delimiter;
			if (debugstream::m_auto_new_line) str += '\n';
		}
		OutputDebugStringA(str.c_str());

		return *this;
	}

	debugstream& debugstream::operator<<(char c)
	{
		return *this << std::string(1, c);
	}

	debugstream& debugstream::operator<<(const char * str)
	{
		return *this << std::string(str);
	}

	debugstream& debugstream::operator<<(bool value)
	{
		static const std::string boolAlphaTrue("true");
		static const std::string boolDigitTrue("1");
		static const std::string boolAlphaFalse("false");
		static const std::string boolDigitFalse("0");
		if (value) {
			return *this << (m_bool_alpha ? boolAlphaTrue : boolDigitTrue);
		} else {
			return *this << (m_bool_alpha ? boolAlphaFalse : boolDigitFalse);
		}
	}

	debugstream& debugstream::operator<<(void(*f)())
	{
		f();
		return *this;
	}

	debugstream& debugstream::operator<<(std::string(*f)())
	{
		return *this << f();
	}

	std::string endl() 
	{
		if (debugstream::m_except_mode_activated) {
			debugstream::m_except_mode_activated = false;
			debugstream::m_auto_new_line = true;
		}
		return "\n";
	}

	std::string newl() 
	{
		debugstream::m_except_mode_activated = true;
		debugstream::m_auto_new_line = false;
		return "\n";
	}

	void keepl()
	{
		debugstream::m_except_mode_activated = true;
		debugstream::m_auto_new_line = false;
	}

	void reset() 
	{
		debugstream::m_bool_alpha = true;
		debugstream::m_auto_new_line = true;
		debugstream::m_auto_delimiter = false;
		debugstream::m_delimiter = " ";
		debugstream::m_except_mode_activated = false;
	}

	bool_alpha::bool_alpha(bool boolAlpha) 
	{ 
		debugstream::m_bool_alpha = boolAlpha; 
	}
		
	auto_new_line::auto_new_line(bool autoNewLine)
	{ 
		if (!debugstream::m_except_mode_activated) {
			debugstream::m_auto_new_line = autoNewLine; 
		}
	}

	auto_delimiter::auto_delimiter(bool autoDelimiter) 
	{ 
		debugstream::m_auto_delimiter = autoDelimiter; 
	}

	auto_delimiter::auto_delimiter(char delimiter, bool autoDelimiter) 
	{ 
		debugstream::m_delimiter = std::string(1, delimiter);  
		debugstream::m_auto_delimiter = autoDelimiter; 
	}

	auto_delimiter::auto_delimiter(std::string const & delimiter, bool autoDelimiter) 
	{ 
		debugstream::m_delimiter = delimiter;  
		debugstream::m_auto_delimiter = autoDelimiter;
	};

	repeat::repeat(char rep_char, size_t rep_count) 
		: debugstream_helper_with_output(std::string(rep_count, rep_char))
	{
	}
	repeat::repeat(std::string const & rep_string, size_t rep_count) 
		: debugstream_helper_with_output()
	{
			std::stringstream stream;
			for (size_t i{ 0 }; i < rep_count; ++i) {
				stream << rep_string;
			}
			m_output_string = stream.str();
	}


	title::title(std::string const & title, char rep_char, size_t max_width)
	{
		if (!debugstream::m_auto_new_line) {
			m_output_string = std::string(1, '\n');
		}

		m_output_string += title + std::string(title.length() + 1 >= max_width ? 0 : max_width - title.length(), rep_char) + std::string("\n");
			
		if (!debugstream::m_auto_new_line) {
			m_output_string += '\n';
		}
	}

	title::title(std::string const & title, std::string const & rep_str, size_t max_width) 
	{
		std::stringstream stream;
		if (!debugstream::m_auto_new_line) stream << '\n';
		stream << title;
		size_t repeat{ title.length() + rep_str.length() >= max_width ? 0 : (max_width - title.length()) / rep_str.length() };
		stream << std::string(max_width - title.length() - repeat * rep_str.length(), ' ');
		for (size_t i{ 0 }; i < repeat; ++i) {
			stream << rep_str;
		}
		if (!debugstream::m_auto_new_line) stream << '\n';
		m_output_string = stream.str();
	}
//}


