# Write your MySQL query statement below
select firstname,lastname,city,state from Person LEFT JOIN Address ON Person.personId=Address.personId; 