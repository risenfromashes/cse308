#include "company.h"
#include "stuff.h"

#include <fmt/format.h>
#include <unordered_map>

#include <iostream>

enum class EntityType { COMPANY, MANAGER, DEVELOPER };

std::string_view to_string(EntityType entity) {
  using enum EntityType;
  switch (entity) {
  case COMPANY:
    return "company";
  case MANAGER:
    return "manager";
  case DEVELOPER:
    return "developer";
  }
  return "";
}

class Context {
public:
  bool show_list(EntityType entity_type) {
    using enum EntityType;
    switch (entity_type) {
    case COMPANY:
      return show_list_impl(entity_type, companies_);
    case MANAGER:
      return show_list_impl(entity_type, managers_);
    case DEVELOPER:
      return show_list_impl(entity_type, developers_);
    }
    return false;
  }

  void add_company() {
    fmt::print("Enter Company Name: ");
    std::string name;
    std::getline(std::cin, name);

    if (companies_.contains(name)) {
      fmt::print("Company with the same name already exists.\n");
      return;
    }
    companies_.emplace(name, std::make_unique<Company>(name));
    fmt::print("Company successfully created.\n");
  }

  void add_manager() {
    if (companies_.size() == 0) {
      fmt::print("There are no companies to add managers to yet.\n");
      return;
    }

    fmt::print("Enter Manager Name: ");
    std::string name;

    std::getline(std::cin, name);

    if (managers_.contains(name)) {
      fmt::print("Manager with the same name already exists.\n");
      return;
    }

    fmt::print("Enter Company Name: ");
    std::string company_name;
    std::getline(std::cin, company_name);

    if (!companies_.contains(company_name)) {
      fmt::print("Company {} not found.\n", company_name);
      return;
    }

    fmt::print("Enter Project Name: ");
    std::string project_name;
    std::getline(std::cin, project_name);

    managers_.emplace(
        name, std::make_unique<Manager>(companies_.at(company_name).get(), name,
                                        project_name));
    fmt::print("Manager successfully added.\n");
  }

  void add_developer() {
    if (managers_.size() == 0) {
      fmt::print("There are no managers to add developers under.\n");
      return;
    }

    fmt::print("Enter Developer's Name: ");
    std::string name;

    std::getline(std::cin, name);

    if (developers_.contains(name)) {
      fmt::print("Developer with the same name already exists.\n");
      return;
    }

    fmt::print("Enter Manager Name: ");
    std::string manager_name;

    std::getline(std::cin, manager_name);

    if (!managers_.contains(manager_name)) {
      fmt::print("Manager not found.\n");
      return;
    }

    developers_.emplace(name, std::make_unique<Developer>(
                                  managers_.at(manager_name).get(), name));
    fmt::print("Developer successfully added.\n");
  }

  void remove_manager(std::string manager) {
    for (auto &[_, d] : developers_) {
      if (d->manager()->name() == manager) {
        developers_.erase(d->name());
        break;
      }
    }
    managers_.erase(manager);
  }

  void remove_company(std::string company) {
    for (auto &[_, m] : managers_) {
      if (m->company()->name() == company) {
        remove_manager(m->name());
        break;
      }
    }
    companies_.erase(company);
  }

  void remove(EntityType entity_type) {
    auto entity = to_string(entity_type);
    auto c = find(entity_type);
    if (!c) {
      return;
    }
    using enum EntityType;
    c->remove();
    switch (entity_type) {
    case COMPANY:
      remove_company(dynamic_cast<Company *>(c)->name());
      break;
    case MANAGER:
      remove_manager(dynamic_cast<Manager *>(c)->name());
      break;
    case DEVELOPER:
      developers_.erase(dynamic_cast<Developer *>(c)->name());
      break;
    }
    fmt::print("Successfully removed.\n");
  }

  Component *find(EntityType entity_type) {
    auto entity = to_string(entity_type);
    fmt::print("Enter {} Name: ", entity);
    std::string name;

    std::getline(std::cin, name);

    bool success = false;
    using enum EntityType;

    switch (entity_type) {
    case COMPANY:
      if (companies_.contains(name)) {
        return companies_.at(name).get();
      }
      break;
    case MANAGER:
      if (managers_.contains(name)) {
        return managers_.at(name).get();
      }
      break;
    case DEVELOPER:
      if (developers_.contains(name)) {
        return developers_.at(name).get();
      }
      break;
    }
    fmt::print("{} named {} not found.\n", entity, name);
    return nullptr;
  }

  void show_detail(EntityType entity_type) {
    if (auto c = find(entity_type)) {
      c->print_details();
    }
  }

  void show_hierarchy(EntityType entity_type) {
    if (auto c = find(entity_type)) {
      c->print_hierarchy();
    }
  }

private:
  template <class T>
  bool
  show_list_impl(EntityType entity_type,
                 std::unordered_map<std::string, std::unique_ptr<T>> &map) {
    fmt::print("\n");
    auto entity = to_string(entity_type);
    if (map.size() == 0) {
      fmt::print("There is no {} currently.\n", entity);
      return false;
    } else {
      fmt::print("{} List:\n", entity);
    }
    for (auto &[n, c] : map) {
      fmt::print("{}\n", n);
    }
    fmt::print("\n");
    return true;
  }

  std::unordered_map<std::string, std::unique_ptr<Company>> companies_;
  std::unordered_map<std::string, std::unique_ptr<Developer>> developers_;
  std::unordered_map<std::string, std::unique_ptr<Manager>> managers_;
};

int main() {
  Context c;
  for (;;) {
    fmt::print("\n\n");
    fmt::print("1. Add Company\n");
    fmt::print("2. Add Manager\n");
    fmt::print("3. Add Developer\n");
    fmt::print("4. Remove Company\n");
    fmt::print("5. Remove Manager\n");
    fmt::print("6. Remove Developer\n");
    fmt::print("7. Show Company List\n");
    fmt::print("8. Show Manager List\n");
    fmt::print("9. Show Developer List\n");
    fmt::print("10. Show Company Details\n");
    fmt::print("11. Show Manager Details\n");
    fmt::print("12. Show Developer Details\n");
    fmt::print("13. Show Company Hierarchy\n");
    fmt::print("14. Show Manager Hierarchy\n");
    fmt::print("15. Exit\n\n");
    fmt::print("Enter Your Choice: ");

    int ch;
    std::cin >> ch;
    fmt::print("\n");

    std::cin.ignore();

    switch (ch) {
    case 1:
      c.add_company();
      break;
    case 2:
      c.add_manager();
      break;
    case 3:
      c.add_developer();
      break;
    case 4:
      c.remove(EntityType::COMPANY);
      break;
    case 5:
      c.remove(EntityType::MANAGER);
      break;
    case 6:
      c.remove(EntityType::DEVELOPER);
      break;
    case 7:
      c.show_list(EntityType::COMPANY);
      break;
    case 8:
      c.show_list(EntityType::MANAGER);
      break;
    case 9:
      c.show_list(EntityType::DEVELOPER);
    case 10:
      c.show_detail(EntityType::COMPANY);
      break;
    case 11:
      c.show_detail(EntityType::MANAGER);
      break;
    case 12:
      c.show_detail(EntityType::DEVELOPER);
      break;
    case 13:
      c.show_hierarchy(EntityType::COMPANY);
      break;
    case 14:
      c.show_hierarchy(EntityType::MANAGER);
      break;
    case 15:
      return 0;
    default:
      fmt::print("Invalid choice.\n");
    }
  }
}
