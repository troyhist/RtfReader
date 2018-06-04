
/**
@interface process RTF blocks
*/

class IRtfPrinter
{
public:
	virtual ~IRtfPrinter()	= 0;

	// outputs current block
	virtual void handle(
		const int			blockType,
		const bool			isSkiped,
		const std::string	&block)	= 0;
};

