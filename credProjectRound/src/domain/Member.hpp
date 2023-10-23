#ifndef __MEMBER__
#define __MEMBER__

#include <string>

class Member
{
private:
  std::string id;
  std::string name;
  std::string phone;
  std::string email;
  std::string profileURL;
  bool valid;

public:
  Member(std::string id, std::string name, std::string phone, std::string email, std::string profileURL);
  Member();
  std::string getId() const;
  bool is_valid() const;
  friend bool operator==(const Member &a, const Member &b);
};

#endif
