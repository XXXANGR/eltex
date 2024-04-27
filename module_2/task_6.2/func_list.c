#include "main.h"


struct Item *DeleteValue(int val, struct Item *head) {
  struct Item *tmp = head;
  // Если пытаемся удалить элемент из пустого списка
  if (NULL == head) {
    printf("List empty!\n");
    return head;
  }
  // Поиск и удаление элемента
  do {
    if (val == tmp->value_id) {
      // Если удаляется единственный элемент списка
      if (tmp->next == tmp->prev) {
        free(tmp);
        return NULL;
      }
      // Перестраиваем связи
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
      // Если элемент удаляется из начала списка, изменяем head
      if (tmp == head)
        head = head->next;
      // Удаляем найденный элемент
      free(tmp);
      return head;
    }
    tmp = tmp->next;
  } while (tmp != head);
  // Если элемент не найден, выводим сообщение
  printf("List does not contain %d!\n", val);
  return head;
}

struct Item *InsertValue(int val, struct Item *head) {

  struct Item *newItem;
  struct Item *tmp = head;

  newItem = malloc(sizeof(struct Item));

  newItem->value_id = val;

  // Вставка элемента в пустой список
  if (NULL == head) {
    newItem->prev = newItem;
    newItem->next = newItem;
    head = newItem;
    return head;
  }

  // Вставка элемента в начало или середину списка
  do {
    if (newItem->value_id <= tmp->value_id) {
      newItem->next = tmp;
      newItem->prev = tmp->prev;
      tmp->prev->next = newItem;
      tmp->prev = newItem;
      if (tmp == head)
        head = newItem;
      return head;
    }
    tmp = tmp->next;
  } while (tmp != head);

  // Вставка элемента в конец списка
  newItem->next = tmp;
  newItem->prev = tmp->prev;
  tmp->prev->next = newItem;
  tmp->prev = newItem;
  enter_data(newItem);
  return head;
}