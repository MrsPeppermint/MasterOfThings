--list the names of all people who starred with Kevin Bacon (1958)
SELECT name
FROM people
WHERE (id IN
--actors in the same movies
(SELECT person_id
FROM stars
WHERE movie_id IN
--movies with Kevin Bacon, 1958
(SELECT movie_id
FROM stars
WHERE person_id IN
(SELECT id
FROM people
WHERE (name = "Kevin Bacon" AND birth = 1958))))
AND people.name != "Kevin Bacon");
