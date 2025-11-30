#include "ArrList.h"

int main() {
TArrList<char> abc;

abc.PushEnd('a');
abc.PushStart('b');
abc.PushEnd('c');

abc.Print();

abc.PopStart();
abc.Print();

abc.PopEnd();
abc.Print();

int idx = 0;
abc.InsertAfter(idx, 'x');
abc.Print();

abc.Remove(idx);
abc.Print();

return 0;
}