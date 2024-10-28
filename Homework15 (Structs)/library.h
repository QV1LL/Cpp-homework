#pragma once

#include <iostream>
#include <string>

using namespace std;

auto isFirstStringBiggerByAlphabet(string text1, string text2) -> bool;

struct Book {
private:
	string title;
	string author;
	string publisher;

public:
	Book() {
		this->title = "???";
		this->author = "???";
		this->publisher = "???";
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

auto setTitle(string title) -> void { this->title = title; }
auto setAuthor(string author) -> void { this->author = author; }
auto setPublisher(string publisher) -> void { this->publisher = publisher; }

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

	Library(uint16_t booksCount) {
		this->books = new Book[booksCount];
		this->booksCount = booksCount;
	}

	Library(uint16_t booksCount, Book* books) {
		this->books = books;
		this->booksCount = booksCount;
	}

	auto getBook(int id) -> Book* {
		return &(this->books[id]);
	}

	auto getBooksCount() -> int {
		return this->booksCount;
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

	auto printBooks() -> void {
		for (int i = 0; i < this->booksCount; i++) {
			Book currentBook = this->books[i];

			cout << "BOOK " << i + 1 << endl
				<< "Title \"" << currentBook.title << "\"" << endl
				<< "Author " << currentBook.author << endl
				<< "Publisher " << currentBook.publisher << endl;
		}
	}

	auto sortBooksByTitle() -> void {
		for (int i = 0; i < this->booksCount; i++) {
			for (int j = 0; j < this->booksCount; j++) {
				Book* book1 = &(this->books[i]);
				Book* book2 = &(this->books[j]);

				if (isFirstStringBiggerByAlphabet(book1->title, book2->title)) {
					auto pTemp = *book1;
					*book1 = *book2;
					*book2 = pTemp;
				}
			}
		}
	}

	auto sortBooksByAuthor() -> void {
		for (int i = 0; i < this->booksCount; i++) {
			for (int j = 0; j < this->booksCount; j++) {
				Book* book1 = &(this->books[i]);
				Book* book2 = &(this->books[j]);

				if (isFirstStringBiggerByAlphabet(book1->author, book2->author)) {
					auto pTemp = *book1;
					*book1 = *book2;
					*book2 = pTemp;
				}
			}
		}
	}

	auto sortBooksByPublisher() -> void {
		for (int i = 0; i < this->booksCount; i++) {
			for (int j = 0; j < this->booksCount; j++) {
				Book* book1 = &(this->books[i]);
				Book* book2 = &(this->books[j]);

				if (isFirstStringBiggerByAlphabet(book1->publisher, book2->publisher)) {
					auto pTemp = *book1;
					*book1 = *book2;
					*book2 = pTemp;
				}
			}
		}
	}
};