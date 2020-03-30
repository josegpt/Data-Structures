package linkedlist

import (
	"errors"
)

// LinkedList provides the methods that can be used in the list
type LinkedList interface {
	AddFirst(val int)
	AddLast(val int)
	ToArray() []int
	InsertBefore(key, val int) error
	InsertAfter(key, val int) error
	Get(key int) (*Node, error)
	GetFirst() (*Node, error)
	GetLast() (*Node, error)
	Remove(key int) (*Node, error)
	Len() int
	IsEmpty() bool
	Clear() LinkedList
	Contains(val int) bool
}

// action is type int to declare if the size increase or decrease
type action int

const (
	inc action = iota
	dec
)

const (
	// EmptyList contains a string for error handling
	EmptyList string = "list is empty"
	// KeyNotFound contains a string for error handling
	KeyNotFound = "key was not found"
)

// List represents of the Linked List
type List struct {
	head *Node
	size int
}

// Node represents each value in the list
type Node struct {
	data int
	next *Node
}

/*
New returns a new list
@param
@return LinkedList
*/
func New() LinkedList {
	return &List{}
}

/*
AddFirst inserts value at the head
@param int
@return
*/
func (l *List) AddFirst(val int) {
	if l.IsEmpty() {
		newNode := new(Node)
		newNode.data = val
		l.head = newNode
	} else {
		newNode := new(Node)
		newNode.data = val
		newNode.next = l.head
		l.head = newNode
	}
	l.updateSize(inc)
}

/*
AddLast inserts value at the end
@param int
@return
*/
func (l *List) AddLast(val int) {
	if l.IsEmpty() {
		l.AddFirst(val)
	} else {
		newNode := new(Node)
		newNode.data = val

		temp := l.head
		for temp.next != nil {
			temp = temp.next
		}
		temp.next = newNode
		l.updateSize(inc)
	}
}

/*
ToArray convers the list to an slice(array) and returns it
@param
@return []int
*/
func (l *List) ToArray() []int {
	helperSlc := []int{}

	if l.IsEmpty() {
		return helperSlc
	}

	temp := l.head
	for temp != nil {
		helperSlc = append(helperSlc, temp.data)
		temp = temp.next
	}
	return helperSlc
}

/*
InsertBefore inserts the value before given key
and returns an error if key was not found
@param int, int
@return error
*/
func (l *List) InsertBefore(key, val int) error {
	if l.IsEmpty() {
		l.AddFirst(val)
	} else {
		newNode := new(Node)
		newNode.data = val

		if l.head.data == key {
			newNode.next = l.head
			l.head = newNode
			l.updateSize(inc)
			return nil
		}

		var prev *Node
		curr := l.head
		for curr != nil && curr.data != key {
			prev = curr
			curr = curr.next
		}

		if curr == nil {
			return errors.New(KeyNotFound)
		}

		newNode.next = curr
		prev.next = newNode
		l.updateSize(inc)
	}

	return nil
}

/*
InsertAfter inserts the value after given
key and returns an error if key is not found
@param int, int
@return error
*/
func (l *List) InsertAfter(key, val int) error {
	if l.IsEmpty() {
		l.AddFirst(val)
	} else {
		newNode := new(Node)
		newNode.data = val

		curr := hasKey(l.head, key)

		if curr == nil {
			return errors.New(KeyNotFound)
		}

		newNode.next = curr.next
		curr.next = newNode
		l.updateSize(inc)
	}

	return nil
}

/*
Get the node with a key
and returns an error if key is not found
@param int
@return *Node, error
*/
func (l *List) Get(key int) (*Node, error) {
	if l.IsEmpty() {
		return nil, errors.New(EmptyList)
	}

	temp := l.head
	for temp != nil && temp.data != key {
		temp = temp.next
	}
	if temp == nil {
		return nil, errors.New(KeyNotFound)
	}

	return temp, nil
}

/*
GetFirst returns the first node or an error if list is empty
@param
@return *Node, error
*/
func (l *List) GetFirst() (*Node, error) {
	if l.IsEmpty() {
		return nil, errors.New(EmptyList)
	}

	return l.head, nil
}

// GetLast returns the last node
func (l *List) GetLast() (*Node, error) {
	if l.IsEmpty() {
		return nil, errors.New(EmptyList)
	}

	temp := l.head
	for temp.next != nil {
		temp = temp.next
	}

	return temp, nil
}

/*
Remove removes the list with given value
and returns an error if key was not found
@param int
@return *Node, error
*/
func (l *List) Remove(key int) (*Node, error) {
	if l.IsEmpty() {
		return nil, errors.New(EmptyList)
	}

	if l.head.data == key {
		temp := l.head
		l.head = l.head.next
		l.updateSize(dec)

		return temp, nil
	}

	prev, curr := hasKeyWithPrev(l.head, key)

	if curr == nil {
		return nil, errors.New(KeyNotFound)
	}

	temp := curr
	prev.next = curr.next
	l.updateSize(dec)

	return temp, nil
}

/*
Len returns the length of the list
@param
@return int
*/
func (l *List) Len() int {
	return l.size
}

/*
IsEmpty return if the empty is empty
@param
@return bool
*/
func (l *List) IsEmpty() bool {
	return l.head == nil
}

/*
Clear return a new Linked List
@param
@return LinkedList
*/
func (l *List) Clear() LinkedList {
	if l.IsEmpty() {
		return l
	}

	*l = List{}
	return l
}

/*
Contains checks if a key exists
@param int
@return bool
*/
func (l *List) Contains(key int) bool {
	return hasKey(l.head, key) != nil
}

/** Helpers **/

/*
updateSize updates the size of the list
@param action type
*/
func (l *List) updateSize(a action) {
	switch a {
	case inc:
		l.size++
	case dec:
		l.size--
	}
}

/*
hasKey search for a given key
@param int
@return *Node
*/
func hasKey(head *Node, key int) *Node {
	temp := head
	for temp != nil && temp.data != key {
		temp = temp.next
	}
	if temp == nil {
		return nil
	}
	return temp
}

func hasKeyWithPrev(head *Node, key int) (*Node, *Node) {
	var prev *Node
	curr := head

	for curr != nil && curr.data != key {
		prev = curr
		curr = curr.next
	}
	if curr == nil {
		return nil, nil
	}

	return prev, curr
}
