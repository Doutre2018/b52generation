#ifndef DEBUG_STREAM_H
#define DEBUG_STREAM_H

#if defined(_WIN32) || defined(WIN32)


// Class utilitaire simple pour faire afficher des commentaires dans la consoles.
//
// Similaire � std::ostream mais sans �tre li� � la librairie std::ostream.
// 
// Plusieurs surcharges sont disponibles : � peut pr�s tout ce qui est streamable!
//
// Quelques manipulateurs de formatage disponibles :
//	- endl				ajoute un saut de ligne (si les sauts de ligne automatique sont activ�, n'ins�re qu'un seul saut de ligne)
//	- newl				ins�re un saut de ligne et d�sactive les sauts de ligne automatique temporairement jusqu'au prochain dendl ou dnewl
//						attention : 
//							- au prochain dendl, le mode auto_new_line est r�activ� ind�pendamment de l'�tat ant�rieur
//							- r�initialiser le auto_new_line n'a aucun effet pendant le dnewl (c'est � dire jusqu'au prochain dendl)
//	- keepl				identique � newl sans faire un saut de ligne
//	- reset				met tous les param�tres par d�faut
//	- bool_alpha		()							active
//						(true)						active 
//						(false)						d�sactive
//		met les valeurs bool�enes en texte ou en nombre
//		par d�faut = true
//	- auto_new_line		()							active
//						(true)						active 
//						(false)						d�sactive
//		ins�re un saut de ligne automatiquement entre chacune des insertions
//		par d�faut = true
//	- auto_delimiter	()							active le d�limiteur automatique
//						(autoDelimiter)				d�termine l'activation du d�limiteur automatique
//						(delimiter)					d�termine le d�limiteur et activer le d�limiteur automatique
//						(delimiter, autoDelimiter)	d�termine le d�limiteur et son activation
//		ins�re une cha�ne de caract�res automatiquement entre chacune des insertions
//		par d�faut = false et " " (un espace)
//	- repeat			('-', 10)					ins�re n fois le caract�re sp�cifi�
//						("- ", 10)					ins�re n fois la cha�ne de caract�res sp�cifi�e
//		ins�re une cha�ne de caract�res construite par r�p�tition
//	- title				("My title", '-', 70)		ins�re le titre et r�p�te le caract�re sp�cifi� jusqu'� un maximum de n caract�res total
//						("My title", " ~ ", 120)	ins�re le titre et r�p�te la cha�ne de caract�re sp�cifi�e jusqu'� un maximum de n caract�res total
//						("My title")				utilise les valeurs par d�faut " -" 80x
//		ins�re une cha�ne de caract�res construite par r�p�tition
//
// Une variable globale est disponible : debugstream debug; // c'est une mis�rable variable globale!
//
// Exemple :
//	#include <debugstream.h>
//	#include <iostream>
//	namespace d = debug;
//	using d::debug;
//
//	class MyStreamableClass{
//		// ...
//		friend std::ostream& operator<<(std::ostream & stream, MyStreamableClass const & myStreamableObject) {
//			return stream << "...someting is inserted to the stream...";
//		}
//	};
//	MyStreamableClass myStreamableObject;
//
//	int variable1{ 1 }, variable2{ -1000 };
//	double variable3{ 3.141592653 }, variable4{ 2.718281828 };
//	debug << d::reset;
//	debug << d::title("Test a character");
//	debug << '!';
//	debug << d::title("Test a c-string and a c++-string");
//	debug << std::string("~o~"); // "-O-" << std::string("~o~");
//	debug << d::title("Test many variables");
//	debug << variable1 << variable2 << variable3 << variable4;
//	debug << d::title("Test many variables on the same line with a delimiter");
//	debug << d::auto_new_line(false) << d::auto_delimiter("  |  ", true);
//	debug << variable1 << variable2 << variable3 << variable4 << d::endl;
//	debug << d::title("Test reset and repeat", "   -");
//	debug << d::reset;
//	debug << d::repeat('?', 25) << d::repeat(" ~o~ ", 25);
//	debug << d::title("Test boolean");
//	debug << d::bool_alpha() << true;
//	debug << d::bool_alpha(false) << false;
//	debug << d::title("Test a custom streamable class");
//	debug << myStreamableObject;
//	debug << d::title("Test newl");
//	debug	<< d::newl << "-next will succeed-"
//			<< d::newl << "Information1 : " << variable1 << " km"
//			<< d::newl << "Information2 : " << variable2 << " km"
//			<< d::newl << "Information3 : " << variable3 << " km"
//			<< d::newl << "Information4 : " << variable4 << " km" << d::endl;
//	debug	<< "-next will failed (endl was called!)-";
//	debug	<< "Information1 : " << variable1 << " km"
//			<< "Information2 : " << variable2 << " km"
//			<< "Information3 : " << variable3 << " km"
//			<< "Information4 : " << variable4 << " km" << d::endl;
//
//
//#include <string>
//#include <iostream>
//#include <sstream>
//#include "type_util.h"

#include <string>
#include <iostream>
#include <sstream>
#include "type_util.h"

//namespace debug {

	class debugstream_helper_no_output;
	class debugstream_helper_with_output;

	class debugstream {
		static bool m_bool_alpha;
		static bool m_auto_new_line;
		static bool m_auto_delimiter;
		static std::string m_delimiter;
		static bool m_except_mode_activated;

		debugstream() = default;
		~debugstream() = default;
		debugstream(debugstream const & d) = delete;
		debugstream& operator=(debugstream const & d) = delete;
		debugstream(debugstream && d) = delete;
		debugstream& operator=(debugstream && d) = delete;

	public:
		debugstream& operator<<(std::string str);
		debugstream& operator<<(char c);
		debugstream& operator<<(const char * str);
		debugstream& operator<<(bool value);
		debugstream& operator<<(void(*f)());
		debugstream& operator<<(std::string(*f)());
		template <typename t, typename std::enable_if<std::is_base_of<debugstream_helper_no_output, t>::value, int>::type = 0>
		debugstream& operator<<(t value);
		template <typename t, typename std::enable_if<std::is_base_of<debugstream_helper_with_output, t>::value, int>::type = 0>
		debugstream& operator<<(t value);
		template <typename t, typename std::enable_if<!std::is_same<t, bool>::value && is_streamable<t>::value, int>::type = 0>
		debugstream& operator<<(t value);
		template <typename t, typename std::enable_if<container_traits<t>::is_conform && is_streamable<typename t::value_type>::value, int>::type = 0>
		debugstream& operator<<(t value);

		friend std::string endl();
		friend std::string newl();
		friend void keepl();
		friend void reset();

		friend class bool_alpha;
		friend class auto_new_line;
		friend class auto_delimiter;
		friend class title;

		friend debugstream& debug();
	};

	debugstream& debug();

	//using dstream = debugstream;

	//extern debugstream debug;

	// Utility functions 
	//	-> must be : 
	//		- void(*)()
	//		- std::string(*)()
	std::string endl();
	std::string newl();
	void keepl();
	void reset();

	//// Utility classes
	////	-> must inherit from debugstream_helper
	class debugstream_helper {};
	class debugstream_helper_no_output : public debugstream_helper {};
	class debugstream_helper_with_output : public debugstream_helper {
	protected: 
		std::string m_output_string;
	public:
		debugstream_helper_with_output() = default;
		debugstream_helper_with_output(std::string const & str) : m_output_string(str) {}

		std::string const & output_string() { return m_output_string; }
	};

	class bool_alpha : public debugstream_helper_no_output
	{
	public:
		bool_alpha(bool boolAlpha = true);
	};

	class auto_new_line : public debugstream_helper_no_output
	{
	public:
		auto_new_line(bool autoNewLine = true);
	};

	class auto_delimiter : public debugstream_helper_no_output
	{
	public:
		auto_delimiter(bool autoDelimiter = true);
		auto_delimiter(char delimiter, bool autoDelimiter = true);
		auto_delimiter(std::string const & delimiter, bool autoDelimiter = true);
	};

	class repeat : public debugstream_helper_with_output
	{
	public:
		repeat(char rep_char, size_t rep_count);
		repeat(std::string const & rep_string, size_t rep_count);
	};

	class title : public debugstream_helper_with_output
	{
	public:
		title(std::string const & title, char rep_char, size_t max_width = 80);
		title(std::string const & title, std::string const & rep_str = " -", size_t max_width = 80);
	};


	template <typename t, typename std::enable_if<!std::is_same<t, bool>::value && is_streamable<t>::value, int>::type>
	debugstream& debugstream::operator<<(t value) {
		std::stringstream stream;
		stream << value;
		return *this << stream.str();
	}
	template <typename t, typename std::enable_if<std::is_base_of<debugstream_helper_no_output, t>::value, int>::type>
	debugstream& debugstream::operator<<(t value) {
		return *this;
	}
	template <typename t, typename std::enable_if<std::is_base_of<debugstream_helper_with_output, t>::value, int>::type>
	debugstream& debugstream::operator<<(t value) {
		return *this << value.output_string();
	}
	template <typename t, typename std::enable_if<container_traits<t>::is_conform && is_streamable<typename t::value_type>::value, int>::type>
	debugstream& debugstream::operator<<(t value) {
		for_each(value.begin(), value.end(), [this](typename t::value_type data) -> void { *this << data; });
		return *this;
	}
//}



#endif // defined(_WIN32) || defined(WIN32)

#endif // DEBUG_STREAM_H