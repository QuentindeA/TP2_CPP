//Taken from stackOerflow
// https://codereview.stackexchange.com/questions/206297/c-split-function-equivalent-to-python-string-split


#if ! defined ( SPLITSTRING_H )
#define SPLITSTRING_H

static constexpr auto whitespace = " \t\v\r\n\f";
static constexpr auto npos = std::string::npos;

std::vector<std::string> split(std::string_view str,
                                std::string_view sep = "",
                                std::size_t maxsplit = std::numeric_limits<std::size_t>::max())
{
    std::vector<std::string> result;
    if (sep.empty())
    {
        for (std::size_t start = str.find_first_not_of(whitespace), splits = 0; start != npos; ++splits)
        {
            if (auto end = str.find_first_of(whitespace, start); end != npos && splits < maxsplit)
            {
                result.emplace_back(str.substr(start, end - start));
                start = str.find_first_not_of(whitespace, end);
            }
            else
            {
                result.emplace_back(str.substr(start));
                break;
            }
        }
    }
    else
    {
        for (std::size_t start = 0, splits = 0; start < str.size(); ++splits)
        {
            if (auto end = str.find(sep, start); end != npos && splits < maxsplit)
            {
                result.emplace_back(str.substr(start, end - start));
                start = end + sep.size();
            }
            else
            {
                result.emplace_back(str.substr(start));
                break;
            }
        }
    }
    return result;
}


#endif // SPLITSTRING_H
