SELECT title
FROM people JOIN starts ON starts.person_id = people.id JOIN movies ON movies.id = starts.movie_id JOIN ratings ON ratings.movie_id = starts.movie_id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;