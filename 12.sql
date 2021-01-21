SELECT title
FROM people JOIN starts ON starts.person_id = people.id JOIN movies ON movies.id = starts.movie_id
WHERE name = "Johnny Depp"
INTERSECT
SELECT title
FROM people JOIN starts ON starts.person_id = person.id JOIN movies ON movies.id = starts.movie_id
WHERE name = "Helena Bonham Carter"