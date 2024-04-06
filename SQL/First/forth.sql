SELECT bat.NAME , YEAR(bat.DATE) , ok.OK_COUNT, dam.DAMAGED_COUNT, sunk.SUNK_COUNT
FROM ships.dbo.BATTLES bat
FULL JOIN ( SELECT BATTLE , COUNT(*) AS OK_COUNT
        FROM ships.dbo.OUTCOMES
        WHERE RESULT = 'ok'
        GROUP BY BATTLE ) ok ON bat.NAME = ok.BATTLE
FULL JOIN ( SELECT BATTLE , COUNT(*) AS DAMAGED_COUNT
        FROM ships.dbo.OUTCOMES
        WHERE RESULT = 'damaged'
        GROUP BY BATTLE) dam ON bat.NAME = dam.BATTLE
FULL JOIN ( SELECT BATTLE , COUNT(*) AS SUNK_COUNT
        FROM ships.dbo.OUTCOMES
        WHERE RESULT = 'sunk'
        GROUP BY BATTLE ) sunk ON bat.NAME = sunk.BATTLE

SELECT bat.NAME, YEAR(bat.DATE) AS YEAR ,out1.RESULT, COUNT(out1.SHIP)
FROM ships.dbo.BATTLES bat
    JOIN ships.dbo.OUTCOMES out1 ON out1.BATTLE = bat.NAME
GROUP BY out1.RESULT, bat.DATE, bat.NAME

SELECT bat.NAME, YEAR(bat.DATE) ,
        SUM(CASE out1.RESULT WHEN 'ok' THEN 1 ELSE 0 END) AS OK_C,
        SUM(CASE out1.RESULT WHEN 'damaged' THEN 1 ELSE 0 END) AS DAMAGED_C,
        SUM(CASE out1.RESULT WHEN 'sunk' THEN 1 ELSE 0 END) AS SUNK_C
FROM ships.dbo.BATTLES bat
    JOIN ships.dbo.OUTCOMES out1 ON out1.BATTLE = bat.NAME
GROUP BY bat.DATE, bat.NAME

SELECT SHIP, COUNT(BATTLE) AS BATTLES_COUNT
FROM ships.dbo.OUTCOMES
GROUP BY SHIP
HAVING COUNT(BATTLE) > 1

SELECT sh.NAME , sh.LAUNCHED,YEAR(bat.DATE) ,YEAR(bat.DATE) - sh.LAUNCHED
FROM ships.dbo.SHIPS sh
    JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP
    JOIN ships.dbo.BATTLES bat ON out1.BATTLE = bat.NAME
WHERE out1.RESULT = 'sunk'

SELECT cl.COUNTRY, MAX(sh.LAUNCHED) AS LAST_LAUNCHED
FROM ships.dbo.CLASSES cl
    JOIN ships.dbo.SHIPS sh ON sh.CLASS = cl.CLASS
GROUP BY cl.COUNTRY
HAVING MAX(sh.LAUNCHED) < 1921


SELECT TITLE, YEAR
FROM movies.dbo.MOVIE
WHERE TITLE LIKE '%Star%' OR TITLE LIKE '%TREK%'
ORDER BY YEAR DESC

SELECT st.MOVIETITLE, st.STARNAME, ms.BIRTHDATE
FROM movies.dbo.STARSIN st
    JOIN movies.dbo.MOVIESTAR ms ON st.STARNAME = ms.NAME
WHERE ms.BIRTHDATE BETWEEN  '1.1.1970' AND '1.7.1980'

SELECT st.STARNAME, COUNT(DISTINCT mv.STUDIONAME)
FROM movies.dbo.MOVIE mv
    JOIN movies.dbo.STARSIN st ON mv.TITLE = st.MOVIETITLE AND mv.TITLE = st.MOVIETITLE
GROUP BY st.STARNAME

SELECT STARNAME , COUNT(MOVIETITLE)
FROM movies.dbo.STARSIN
WHERE MOVIEYEAR >= 1978
GROUP BY STARNAME
HAVING COUNT(MOVIETITLE) > 1

SELECT TITLE, LENGTH
FROM movies.dbo.MOVIE
WHERE LENGTH >= ALL (SELECT LENGTH FROM movies.dbo.MOVIE WHERE LENGTH is not NULL)

SELECT TITLE, LENGTH
FROM movies.dbo.MOVIE
WHERE LENGTH = ALL (SELECT MAX(LENGTH) FROM movies.dbo.MOVIE)


SELECT DISTINCT st.MOVIETITLE
FROM movies.dbo.STARSIN st
WHERE EXISTS(SELECT *
             FROM movies.dbo.STARSIN st2
             WHERE st.STARNAME = st2.STARNAME
                AND (NOT(st2.STARNAME LIKE '%k%')
                AND NOT(st2.STARNAME LIKE '%b%')))
    AND st.MOVIEYEAR  <= 1982

SELECT *
FROM (SELECT STUDIONAME,LENGTH FROM movies.dbo.MOVIE WHERE TITLE = 'Terms of Endearment' AND YEAR = 1983 ) sl
    JOIN movies.dbo.MOVIE mv ON mv.STUDIONAME = sl.STUDIONAME
WHERE mv.LENGTH >= sl.LENGTH OR mv.LENGTH is NULL



SELECT *
FROM movies.dbo.STARSIN
    JOIN movies.dbo.MOVIEEXEC ON STARNAME = NAME

SELECT TITLE, INCOLOR, STUDIONAME, YEAR
FROM movies.dbo.MOVIE mv
WHERE YEAR < (SELECT MIN(YEAR)
              FROM movies.dbo.MOVIE mv2
              WHERE mv.STUDIONAME = mv2.STUDIONAME
                AND  mv2.INCOLOR = 'y')
    AND INCOLOR = 'N'

SELECT stud.NAME, COUNT(st.STARNAME) AS STAR_COUNT
FROM movies.dbo.STUDIO stud
    LEFT JOIN movies.dbo.MOVIE mv ON stud.NAME = mv.STUDIONAME
    LEFT JOIN movies.dbo.STARSIN st ON mv.TITLE = st.MOVIETITLE AND st.MOVIEYEAR = mv.YEAR
GROUP BY stud.NAME
HAVING COUNT(st.STARNAME) < 4

SELECT prod.maker, p.model
FROM pc.dbo.product prod
    JOIN pc.dbo.pc p ON prod.model = p.model
WHERE p.price < (SELECT MIN(price)
               FROM pc.dbo.laptop lap
                    JOIN pc.dbo.product prod2 ON prod2.model = lap.model
               WHERE prod.maker = prod2.maker)

SELECT prod.maker, p.model
FROM pc.dbo.product prod
    JOIN pc.dbo.pc p ON prod.model = p.model
WHERE p.price < (SELECT MIN(price)
               FROM pc.dbo.laptop lap
                    JOIN pc.dbo.product prod2 ON prod2.model = lap.model
               WHERE prod.maker = prod2.maker)
    AND p.price < (SELECT MIN(price)
               FROM pc.dbo.printer prin
                    JOIN pc.dbo.product prod3 ON prod3.model = prin.model
               WHERE prod.maker = prod3.maker)

SELECT model, MAX(price)
FROM pc.dbo.pc
GROUP BY model
ORDER BY MAX(price) DESC

SELECT model, MAX(hd) ,MIN(hd)
FROM pc.dbo.pc
GROUP BY model
HAVING MAX(hd) - MIN(hd) >= 20

SELECT (SELECT COUNT(*) FROM pc.dbo.pc WHERE prod.model = pc.model)
FROM pc.dbo.product prod
    LEFT JOIN (SELECT model FROM pc.dbo.printer WHERE type = 'Laser') prin ON prin.model = prod.model

SELECT maker, AVG(lap.price) ,AVG(pc.price)
FROM pc.dbo.product prod
    LEFT JOIN (SELECT model, price FROM pc.dbo.pc) pc ON pc.model = prod.model
    LEFT JOIN (SELECT model, price FROM pc.dbo.laptop) lap ON lap.model = prod.model
GROUP BY maker
HAVING AVG(lap.price) >= AVG(pc.price)

SELECT NAME, CLASS, LAUNCHED
FROM ships.dbo.SHIPS
WHERE NAME = CLASS

SELECT *
FROM ships.dbo.OUTCOMES
WHERE SHIP LIKE 'C%' OR SHIP LIKE 'K%'

SELECT out1.BATTLE, SUM(CASE out1.RESULT WHEN 'sunk' THEN 1 ELSE 0 END) AS SUNK_SHIPS
FROM ships.dbo.OUTCOMES out1
    LEFT JOIN ships.dbo.SHIPS sh ON  out1.SHIP = sh.NAME
    LEFT JOIN ships.dbo.CLASSES cl ON sh.CLASS = cl.CLASS
WHERE cl.COUNTRY = 'USA'
GROUP BY out1.BATTLE
HAVING SUM(CASE out1.RESULT WHEN 'sunk' THEN 1 ELSE 0 END) > 0

SELECT NAME, LAUNCHED
FROM ships.dbo.SHIPS
WHERE NOT(NAME LIKE '%j%') AND NOT(NAME LIKE '%k%')
ORDER BY LAUNCHED DESC

SELECT out1.BATTLE, SUM(CASE out1.RESULT WHEN 'sunk' THEN 1 ELSE 0 END) AS SUNK_COUNT
FROM ships.dbo.OUTCOMES out1
    LEFT JOIN ships.dbo.SHIPS sh ON sh.NAME = out1.SHIP
    LEFT JOIN ships.dbo.CLASSES cl ON sh.CLASS = cl.CLASS
WHERE cl.COUNTRY = 'Japan'
GROUP BY out1.BATTLE
HAVING SUM(CASE out1.RESULT WHEN 'sunk' THEN 1 ELSE 0 END) > 0