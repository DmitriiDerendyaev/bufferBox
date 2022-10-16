#include <iostream>
#include <stdexcept>
using namespace std;


struct CustomDate
{
    int year;
    int month;
    int day;
};


struct DataStruct
{
    string name;
    string number_account;
    int value_account;
    CustomDate last_change;
};


template<typename universal_variable>
class SingleLink
{
private:
    template<typename universal_variable>
    class Node
    {
    public:
        universal_variable _data;
        Node* _next_node_address;

        Node(universal_variable data = universal_variable(), Node* next_node_address = nullptr) { this->_data = data, this->_next_node_address = _next_node_address; }

    };

    Node<universal_variable>* head_list;
    int _size;

    Node<universal_variable>* search_name(string value)
    {
        if (head_list == nullptr) {
            throw out_of_range("Array is empty!");
        }
        else
        {
            Node<universal_variable>* currentNode = this->head_list;
            while (currentNode->_next_node_address != nullptr)
            {
                if (currentNode->_data.name.find(value) != string::npos) break;
                currentNode = currentNode->_next_node_address;
            }
            return currentNode;
        }
    }

    Node<universal_variable>* search_account(string value)
    {
        if (head_list == nullptr) {
            throw out_of_range("Array is empty!");
        }
        else
        {
            Node<universal_variable>* currentNode = this->head_list;
            while (currentNode->_next_node_address != nullptr)
            {
                if (currentNode->_data.number_account == value) break;
                currentNode = currentNode->_next_node_address;
            }
            return currentNode;
        }
    }

    Node<universal_variable>* search_value_account(int value)
    {
        if (head_list == nullptr) {
            throw out_of_range("Array is empty!");
        }
        else
        {
            Node<universal_variable>* currentNode = this->head_list;
            while (currentNode->_next_node_address != nullptr)
            {
                if (currentNode->_data.value_account == value) break;
                currentNode = currentNode->_next_node_address;
            }
            return currentNode;
        }
    }

public:
    SingleLink()
    {
        head_list = nullptr;
        _size = 0;
    }
    ~SingleLink()
    {

    }

    void pushBack(universal_variable element)
    {
        if (head_list == nullptr) {
            head_list = new Node<universal_variable>(element);
        }
        else
        {
            Node<universal_variable>* currentNode = this->head_list;
            while (currentNode->_next_node_address != nullptr)
            {
                currentNode = currentNode->_next_node_address;
            }
            currentNode->_next_node_address = new Node<universal_variable>(element);
        }
        _size++;
    }


    void pushStart(universal_variable element)
    {
        if (head_list == nullptr) {
            head_list = new Node<universal_variable>(element);
        }
        else
        {
            Node<universal_variable>* old_had = head_list;
            head_list = new Node<universal_variable>(element, old_had);
            head_list->_next_node_address = old_had;
        }
        _size++;
    }


    void deleteStart()
    {
        if (head_list == nullptr) {
            throw out_of_range("Array is empty!");
        }
        else
        {
            Node<universal_variable>* toDelete = head_list;
            head_list = head_list->_next_node_address;
            delete toDelete;
        }
        _size--;
    }


    void deleteBack()
    {
        if (head_list == nullptr) {
            throw out_of_range("Array is empty!");
        }
        else if (_size == 1)
        {
            head_list = nullptr;
        }
        else
        {
            Node<universal_variable>* currentNode = this->head_list;
            for (int i = 1; i < _size - 1; i++)
            {
                currentNode = currentNode->_next_node_address;
            }

            Node<universal_variable>* toDelete = currentNode->_next_node_address;
            currentNode->_next_node_address = nullptr;
        }
        _size--;
    }



    DataStruct search_by_field(int field, DataStruct value)
    {
        if (field < 1 or field > 3) throw out_of_range("Out of array!");
        else if (field == 1) return search_name(value.name)->_data;
        else if (field == 2) return search_account(value.number_account)->_data;
        else if (field == 3) return search_value_account(value.value_account)->_data;
    }

    void add_after_finded(int field, DataStruct value, DataStruct adding_element)
    {
        if (field < 1 or field > 3) throw out_of_range("Out of array!");
        else if (field == 1) {
            Node<universal_variable>* new_node = new Node<universal_variable>(adding_element);
            new_node->_next_node_address = search_name(value.name)->_next_node_address;
            search_name(value.name)->_next_node_address = new_node;
        }
        else if (field == 2) search_account(value.number_account)->_data;
        else if (field == 3) search_value_account(value.value_account)->_data;
    }

    void delete_after_find(int field, DataStruct value) {
        if (field < 1 or field > 3) throw out_of_range("Out of array!");
        else if (field == 1) {
            Node<universal_variable>* previous_node = search_name(value.name);
            Node<universal_variable>* toDelete = previous_node->_next_node_address;
            previous_node->_next_node_address = toDelete->_next_node_address;
            delete toDelete;
            _size--;
        }
        else if (field == 2) search_account(value.number_account)->_data;
        else if (field == 3) search_value_account(value.value_account)->_data;
    }

};


void print_struct(DataStruct exemplar)
{
    cout << "Full name: " << exemplar.name << endl;
    cout << "Account number: " << exemplar.number_account << endl;
    cout << "The amount on the account: " << exemplar.value_account << endl;
    cout << "The last modified date: " << exemplar.last_change.day << "/" << exemplar.last_change.month << "/" << exemplar.last_change.year << endl << endl;
}

DataStruct create_struct()
{
    DataStruct tmp;
    cout << "Enter your full name: ";
    cin >> tmp.name;

    cout << "Enter account number: ";
    cin >> tmp.number_account;

    cout << "Enter the amount on the account: ";
    cin >> tmp.value_account;

    char a;
    cout << "Enter the last modified date (for example: 15/10/2020): ";
    cin >> tmp.last_change.day >> a >> tmp.last_change.month >> a >> tmp.last_change.year;
    cout << endl;
    return tmp;

}
enum userChoice {
    MENU = 0,
    PUSH_BACK = 1,
    PUSH_START = 2,
    DELETE_BACK = 3,
    DELETE_START = 4,
    FIND_BY_FIELD = 5,
    ADD_AFTER_FOUND = 6,
    DELETE_FOUND = 7,

};



int main() {
    SingleLink<DataStruct> SingleList;


    string menu = "PUSH_BACK = 1\n PUSH_START = 2\n DELETE_BACK = 3\n DELETE_START = 4\n FIND_BY_FIELD = 5\n ADD_AFTER_FOUND = 6\n DELETE_FOUND = 7\n";

    int user_choice, indexElement;
    while (true)
    {
        cout << endl << menu << endl;
        cin >> user_choice;
        switch (user_choice)
        {
        case PUSH_BACK:
        {
            try
            {
                DataStruct MyStruct;
                MyStruct = create_struct();
                SingleList.pushBack(MyStruct);
            }
            catch (const out_of_range& error)
            {
                cerr << "Unknown error: " << error.what() << endl;
            }
            break;
        }
        case PUSH_START:
        {
            try
            {
                DataStruct MyStruct;
                MyStruct = create_struct();
                SingleList.pushStart(MyStruct);
            }
            catch (const out_of_range& error)
            {
                cerr << "Unknown error: " << error.what() << endl;
            }
            break;
        }
        case DELETE_BACK:
        {
            try
            {
                SingleList.deleteBack();
            }
            catch (const out_of_range& error)
            {
                cerr << "List is empty!: " << error.what() << endl;
            }
            break;
        }
        case DELETE_START:
        {
            try
            {
                SingleList.deleteStart();
            }
            catch (const logic_error& error)
            {
                cerr << "List is empty!: " << error.what() << endl;
            }
            break;
        }

        case FIND_BY_FIELD:
        {
            try
            {
                cout << "Enter number field for search: ";
                int num_field;
                cin >> num_field;

                DataStruct tmp;
                if (num_field == 1)
                {
                    cout << "Enter full name for search: ";
                    cin >> tmp.name;
                }
                if (num_field == 2)
                {
                    cout << "Enter number account for search: ";
                    cin >> tmp.number_account;
                }
                if (num_field == 3)
                {
                    cout << "Enter value account for search: ";
                    cin >> tmp.value_account;
                }
                cout << endl << endl << "Found element: " << endl;
                print_struct(SingleList.search_by_field(num_field, tmp));
            }
            catch (const out_of_range& error)
            {
                cerr << "List is empty!: " << error.what() << endl;
            }
            break;
        }
        case ADD_AFTER_FOUND:
        {
            try
            {
                cout << "Enter number field for search: ";
                int num_field;
                cin >> num_field;

                DataStruct tmp;
                DataStruct for_past;
                if (num_field == 1)
                {
                    cout << "Enter full name for search: ";
                    cin >> tmp.name;
                }
                if (num_field == 2)
                {
                    cout << "Enter number account for search: ";
                    cin >> tmp.number_account;
                }
                if (num_field == 3)
                {
                    cout << "Enter value account for search: ";
                    cin >> tmp.value_account;
                }
                for_past = create_struct();
                cout << endl << endl << "Found element: " << endl;
                SingleList.add_after_finded(num_field, tmp, for_past);
            }
            catch (const logic_error& error)
            {
                cerr << "Logical Error: " << error.what() << endl;
            }
            break;
        }
        case DELETE_FOUND:
        {
            try
            {


            }
            catch (const logic_error& error)
            {
                cerr << "Logical Error: " << error.what() << endl;
            }
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
