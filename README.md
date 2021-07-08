# lms
A Library management system (LMS) which manages all the books in a given
directory. The program, written in c++ starts with a directory as input, and manages the books in that
directory. The LMS maintains books and their relevant details in a separate file. The software is Command Line
Interface based and is yet to be converted to a GUI.
The software automatically detects all files in the directory and is able to detect the newly added
books as well.
The LMS includes following functionalities:
- List all books along with their filename, title, and author name.
- Search for a book by its title or author name, and show the matching books as a list.
- Display a book from any of the above two lists.

The LMS is also able to perform the following analytics tasks:
- If the type of the selected book is novel, given an input word, the LMS
shows the top 5 chapters, or top 5 paragraphs, where this word appears most of the times.
- If the type of the selected book is play, then given an input character, the LMS
shows a list of all other characters which appear in at least one scene with the input
character.

Note: The software has been tested on Project Gutenberg books. 


