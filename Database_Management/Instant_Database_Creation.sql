-- Step 1: Creating the 'Book' table
create table Book (
    bookID int primary key,      -- Primary key for bookID
    title varchar2(100),         -- Book title
    author varchar2(100),        -- Book author
    ISBN varchar2(20)            -- Book ISBN (unique)
);

-- Inserting records into the 'Book' table
insert into Book (bookID, title, author, ISBN) 
values (1, 'The Great Gatsby', 'F. Scott Fitzgerald', '9780743273565');
insert into Book (bookID, title, author, ISBN) 
values (2, 'To Kill a Mockingbird', 'Harper Lee', '9780060935467');
insert into Book (bookID, title, author, ISBN) 
values (3, '1984', 'George Orwell', '9780451524935');

-- Step 2: Creating the 'Member' table
create table Member (
    memberID int primary key,     -- Primary key for memberID
    name varchar2(100),           -- Member's name
    contact varchar2(50)          -- Member's contact information (phone or email)
);

-- Inserting records into the 'Member' table
insert into Member (memberID, name, contact) 
values (1, 'John Doe', 'johndoe@email.com');
insert into Member (memberID, name, contact) 
values (2, 'Jane Smith', 'janesmith@email.com');
insert into Member (memberID, name, contact) 
values (3, 'Mark Brown', 'markbrown@email.com');

-- Step 3: Creating the 'Loan' table (junction table for many-to-many relation)
create table Loan (
    loanID int primary key,         -- Primary key for loanID
    loanDate date,                  -- Date the book was loaned
    returnDate date,                -- Date the book should be returned
    memberID int,                   -- Foreign key referencing Member
    bookID int,                     -- Foreign key referencing Book
    foreign key (memberID) references Member(memberID),  -- Foreign key for memberID
    foreign key (bookID) references Book(bookID)         -- Foreign key for bookID
);

-- Inserting records into the 'Loan' table
insert into Loan (loanID, loanDate, returnDate, memberID, bookID) 
values (1, to_date('2025-05-01', 'yyyy-mm-dd'), to_date('2025-05-15', 'yyyy-mm-dd'), 1, 1);
insert into Loan (loanID, loanDate, returnDate, memberID, bookID) 
values (2, to_date('2025-05-02', 'yyyy-mm-dd'), to_date('2025-05-16', 'yyyy-mm-dd'), 2, 2);
insert into Loan (loanID, loanDate, returnDate, memberID, bookID) 
values (3, to_date('2025-05-03', 'yyyy-mm-dd'), to_date('2025-05-17', 'yyyy-mm-dd'), 3, 3);

-- Step 4: Querying the data

-- 1. Select all books
select * from Book;

-- 2. Select all members
select * from Member;

-- 3. Select all loans with member and book details
select Loan.loanID, Loan.loanDate, Loan.returnDate, Member.name as MemberName, Book.title as BookTitle
from Loan
join Member on Loan.memberID = Member.memberID
join Book on Loan.bookID = Book.bookID;

-- 4. Find all books loaned by a particular member (example: memberID 1)
select Book.title
from Loan
join Book on Loan.bookID = Book.bookID
where Loan.memberID = 1;

-- 5. Find all members who borrowed a particular book (example: bookID 1)
select Member.name
from Loan
join Member on Loan.memberID = Member.memberID
where Loan.bookID = 1;

-- 6. Find books that are currently loaned out (no return date yet)
select Book.title
from Loan
join Book on Loan.bookID = Book.bookID
where Loan.returnDate is null;

-- 7. Find overdue books (return date before today's date)
select Book.title, Member.name
from Loan
join Book on Loan.bookID = Book.bookID
join Member on Loan.memberID = Member.memberID
where Loan.returnDate < sysdate;
