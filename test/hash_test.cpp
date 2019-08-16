#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>

using namespace boost::multi_index;

struct person
{
  int id;
  std::string name;
  int age;

  person(int id, const std::string &name, int age)
      : id(id), name(name), age(age) {}

  void print() const
  {
    std::cout << id << "," << name << "," << age << std::endl;
  }
};

struct id
{
};
struct name
{
};
struct age
{
};

typedef multi_index_container<
    person,
    indexed_by<
        ordered_unique<tag<id>, member<person, int, &person::id>>,
        ordered_unique<tag<name>, member<person, std::string, &person::name>>,
        ordered_unique<tag<age>, member<person, int, &person::age>>>>
    dictionary;

int main()
{
  dictionary dict;
  dict.insert(person(3, "Akira", 30));
  dict.insert(person(1, "Millia", 20));
  dict.insert(person(4, "Johnny", 10));

  // IDをキーにするmap
  {
    typedef dictionary::index<id>::type id_map;
    id_map &m = dict.get<id>();

    // IDをキーにして検索
    id_map::iterator it = m.find(1);
    if (it != m.end())
    {
      it->print();
    }
  }

  // 名前をキーにするmap
  {
    typedef dictionary::index<name>::type name_map;
    name_map &m = dict.get<name>();

    // 名前をキーにして検索
    name_map::iterator it = m.find("Akira");
    if (it != m.end())
    {
      it->print();
    }
  }

  // 年齢をキーにするmap
  {
    typedef dictionary::index<age>::type age_map;
    age_map &m = dict.get<age>();

    // 年齢をキーにして検索
    age_map::iterator it = m.find(10);
    if (it != m.end())
    {
      it->print();
    }
  }
}