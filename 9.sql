SELECT name
FROM people JOIN starts ON starts.person_id = people.id JOIN movies ON movies.id = starts.movie_id
WHERE year = 2004;
GROUP BY name, person_id
ORDER BY birth;