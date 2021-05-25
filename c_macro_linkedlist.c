#include <stdio.h>
#include "List.h"

decl_List(int, i32)
def_List(int, i32)

decl_List(char, char)
def_List(char, char)

decl_List(int*, i32p)
def_List(int*, i32p)

void i32_print_iter(const int* item) {
	printf("%d\n", *item);
}

bool i32_equals(const int lhs, const int rhs) {
	return lhs == rhs;
}

int main() {
	List_char list2 = List_char_new();
	List_i32p list3 = List_i32p_new();
	list2.f->dispose(&list2, NULL);
	list3.f->dispose(&list3, NULL);

	List_i32 list = List_i32_new();

	for (size_t i = 0; i < 10; i++)
		list.f->push_back(&list, i);

	list.f->for_each(&list, i32_print_iter);

	if (list.f->unsafe_contains(&list, 11))
		printf("list contains 11\n");
	else
		printf("list not contains 11\n");

	if (list.f->unsafe_contains(&list, 5))
		printf("list contains 5\n");
	else
		printf("list not contains 5\n");

	if (list.f->contains_by(&list, 7, i32_equals))
		printf("list contains 7\n");
	else
		printf("list not contains 7\n");
	
	printf("%d", list.f->get_length(&list));

	list.f->dispose(&list, NULL);
}
