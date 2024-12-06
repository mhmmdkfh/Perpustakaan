#ifndef buku.h
#define buku.h

#define MAX_BOOKS 100
#define MAX_CATEGORY 5
#define MAX_NAME_LENGTH 50

// Struct untuk buku
typedef struct {
    char title[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
} Book;

// Data buku dummy
Book books[MAX_BOOKS] = {
    {"The Pragmatic Programmer", "Andy Hunt", "Programming"},
    {"Clean Code", "Robert C. Martin", "Programming"},
    {"To Kill a Mockingbird", "Harper Lee", "Fiction"},
    {"1984", "George Orwell", "Fiction"},
    {"A Brief History of Time", "Stephen Hawking", "Science"},
    {"The Selfish Gene", "Richard Dawkins", "Science"},
    {"Think and Grow Rich", "Napoleon Hill", "Self-Help"},
    {"Atomic Habits", "James Clear", "Self-Help"},
    {"The Art of War", "Sun Tzu", "History"},
    {"Sapiens", "Yuval Noah Harari", "History"}
};

int total_books = 10;

// Fungsi untuk menampilkan buku berdasarkan kategori
void displayBooksByCategory(const char *category) {
    int found = 0;
    int i;
    printf("\nDaftar buku dalam kategori '%s':\n", category);
    printf("-------------------------------------------------\n");
    for (i = 0; i < total_books; i++) {
        if (strcmp(books[i].category, category) == 0) {
            printf("Judul: %s\n", books[i].title);
            printf("Penulis: %s\n", books[i].author);
            printf("-------------------------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Tidak ada buku dalam kategori ini.\n");
    }
}

// Fungsi untuk menampilkan semua kategori unik
void displayAllCategories() {
    char categories[MAX_CATEGORY][MAX_NAME_LENGTH];
    int total_categories = 0;
    int i,j;

    printf("\nKategori yang tersedia:\n");
    printf("-----------------------------\n");
    for (i = 0; i < total_books; i++) {
        int exists = 0;
        for (j = 0; j < total_categories; j++) {
            if (strcmp(books[i].category, categories[j]) == 0) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            strcpy(categories[total_categories], books[i].category);
            total_categories++;
        }
    }

    for (i = 0; i < total_categories; i++) {
        printf("- %s\n", categories[i]);
    }
    printf("-----------------------------\n");
}

// Fungsi untuk menambahkan buku baru
void addBook() {
    if (total_books >= MAX_BOOKS) {
        printf("Kapasitas maksimum buku tercapai. Tidak dapat menambah buku baru.\n");
        return;
    }

    Book newBook;

    printf("\nMasukkan judul buku: ");
    getchar(); // Membersihkan buffer
    fgets(newBook.title, MAX_NAME_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Menghapus newline

    printf("Masukkan nama penulis: ");
    fgets(newBook.author, MAX_NAME_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Menghapus newline

    printf("Masukkan kategori buku: ");
    fgets(newBook.category, MAX_NAME_LENGTH, stdin);
    newBook.category[strcspn(newBook.category, "\n")] = 0; // Menghapus newline

    books[total_books++] = newBook;
    printf("Buku berhasil ditambahkan!\n");
}

void displayAllbooks () {
	int a;
	
	printf("\nSemua buku yang tersedia:\n");
	printf("\n--------------------------\n");
	for (a = 0; a < total_books; a++) {
		printf("Judul: %s\n", books[a].title);
		printf("Penulis: %s\n", books[a].author);
		printf("Kategori: %s\n", books[a].category);
		printf("\n--------------------------\n");
	}
}
// Menu utama
void menu() {
    int choice;
    char category[MAX_NAME_LENGTH];

    do {
        printf("\n=== Aplikasi Daftar Buku ===\n");
        printf("1. Tampilkan semua kategori\n");
        printf("2. Tampilkan buku berdasarkan kategori\n");
        printf("3. Tambah buku baru\n");
        printf("4. Tampilkan semua buku\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllCategories();
                break;
            case 2:
                printf("\nMasukkan kategori: ");
                getchar(); // Membersihkan buffer
                fgets(category, MAX_NAME_LENGTH, stdin);
                category[strcspn(category, "\n")] = 0; // Menghapus newline
                displayBooksByCategory(category);
                break;
            case 3:
                addBook();
                break;
            case 4:
                displayAllbooks();
                break;
            case 5:
            	printf("Keluar dari aplikasi. Sampai jumpa!\n");
            	break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice !=5);
}

#endif
