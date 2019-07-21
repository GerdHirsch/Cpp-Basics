#if !defined PROTOCOL_VIOLATION_EXCEPTION
#define PROTOCOL_VIOLATION_EXCEPTION

#include <exception>

class ProtocolViolationException : public std::exception {
public:
	ProtocolViolationException(char const* message):message(message){} 
	char const* what() const noexcept { return message;}
private:
	char const* message;
};

#endif // PROTOCOL_VIOLATION_EXCEPTION
