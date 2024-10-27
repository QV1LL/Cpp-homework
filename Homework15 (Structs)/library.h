#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Book {
private:
	string title;
	string author;
	string publisher;

public:
	Book() {

	}

	Book(string title, string author, string publisher) {
		this->title = title;
		this->author = author;
		this->publisher = publisher;
	}

	auto setStatements(string title, string author, string publisher) -> void {
		this->title = title;
		this->author = author;
		this->publisher = publisher;
	}

	auto getTitle() -> string { return this->title; }
	auto getAuthor() -> string { return this->author; }
	auto getPublisher() -> string { return this->publisher; }

	friend struct Library;
};

struct Library {
private:
		Book* books;
		uint16_t booksCount;

public:
	Library() {
		this->books = new Book[10];
		this->booksCount = 10;
	}

	Library(int booksCount) {
		this->books = new Book[booksCount];
		this->booksCount = booksCount;
	}

	Library(int booksCount, Book* books) {
		this->books = books;
		this->booksCount = booksCount;
	}

	auto getBook(int id) -> Book {
		return this->books[id];
	}

	auto getBooksCount() -> int {
		return this->booksCount;
	}

	auto setBook(Book& book, int id) -> void {
		delete &(this->books[id]);

		this->books[id] = book;
	}

	auto findBookByAuthor(string author, int entrance) -> Book* {
		int currentEntrance = 0;

		for (int i = 0; i < this->booksCount; i++) {
			if (this->books[i].author == author) {
				currentEntrance++;

				if (currentEntrance == entrance)
					return &(this->books[i]);
			}
		}

		return nullptr;
	}

	auto findBookByTitle(string title, int entrance) -> Book* {
		int currentEntrance = 0;

		for (int i = 0; i < this->booksCount; i++) {
			if (this->books[i].author == title) {
				currentEntrance++;

				if (currentEntrance == entrance)
					return &(this->books[i]);
			}
		}

		return nullptr;
	}
};