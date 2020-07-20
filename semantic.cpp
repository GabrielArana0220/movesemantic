#include <iostream>
#include <algorithm>
#include <string.h>

std::string mayuscula(std::string &&ini)
{
    std::transform(ini.begin(), ini.end(), ini.begin(), ::toupper);
    return std::move(ini);
}


class cadena{
    char* caden;
public:
    cadena(const char* p)
    {
        size_t size = strlen(p) + 1;
        caden = new char[size];
        memcpy(caden, p, size);
    }
    ~cadena()
    {
        delete[] caden;
    }
    cadena(const cadena& o)
    {
        size_t size = strlen(o.caden) + 1;
        caden = new char[size];
        memcpy(caden, o.caden, size);
    }
    cadena(cadena&& o)
    {
        caden = o.caden;
        o.caden = nullptr;
    }
    cadena& operator=(cadena o)
    {
        std::swap(caden, o.caden);
        return *this;
    }
};
int main()
{
    cadena r("valor");

    cadena t = r;
}
