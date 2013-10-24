/// BulletML のパーサ・ツリー by Xerces
/**
 * Xerces による BulletML のパーサ
 */

#ifndef BULLETMLPARSER_XERCES_H_
#define BULLETMLPARSER_XERCES_H_

#ifdef USE_XERCES

class BulletMLParserXerces : public BulletMLParser {
public:
    explicit BulletMLParserXerces(const char* filename);
    virtual ~BulletMLParserXerces();

    virtual void parse();

private:
	friend class BulletMLParserXercesSAXHandler;
};

#endif // USE_XERCES

#endif // ! BULLETMLPARSER_XERCES_H_
