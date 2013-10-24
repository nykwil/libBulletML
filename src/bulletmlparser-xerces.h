/// BulletML �̃p�[�T�E�c���[ by Xerces
/**
 * Xerces �ɂ�� BulletML �̃p�[�T
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