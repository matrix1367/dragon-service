#ifndef CDMESSAGE_H
#define CDMESSAGE_H


class CDMessage
{
    public:
        CDMessage();
        virtual ~CDMessage();
        void SetTitle(std::string title);
        std::string GetTitle();
    protected:
    private:
        std::string m_title;
        std::string m_description;
};

#endif // CDMESSAGE_H
