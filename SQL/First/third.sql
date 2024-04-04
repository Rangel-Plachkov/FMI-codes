
SELECT AVG(speed)
FROM pc.dbo.pc

SELECT prod.maker, AVG(lap.screen)
FROM pc.dbo.laptop lap
    JOIN pc.dbo.product prod ON prod.model = lap.model
GROUP BY prod.maker

SELECT AVG(speed)
FROM pc.dbo.laptop
WHERE price >= 1000


SELECT AVG(p.price)
FROM pc.dbo.pc p
    JOIN pc.dbo.product prod ON p.model = prod.model
WHERE prod.maker = 'A' and prod.type = 'PC'

SELECT AVG(u.price)
FROM pc.dbo.product p
    JOIN (SELECT model,price FROM pc.dbo.pc
        UNION
        SELECT model,price FROM pc.dbo.laptop) u ON p.model = u.model
WHERE p.maker = 'B'

SELECT p.speed ,AVG(p.price) AS AVG_SPEED
FROM pc.dbo.pc p
GROUP BY p.speed



SELECT *
FROM (SELECT prod.maker,COUNT(maker) AS count
        FROM pc.dbo.product prod
        WHERE prod.type = 'PC'
        GROUP BY maker) s
WHERE s.count >= 3

SELECT prod.maker
FROM pc.dbo.product prod
WHERE prod.type = 'PC'
GROUP BY maker
HAVING COUNT(maker) >= 3

SELECT prod.maker
FROM pc.dbo.product prod
    JOIN pc.dbo.pc p ON p.model = prod.model
WHERE p.price = (SELECT MAX(price) FROM pc.dbo.pc)

SELECT p.speed,AVG(p.price)
FROM pc.dbo.pc p
WHERE p.speed > 800
GROUP BY p.speed

SELECT AVG(p.hd)
FROM pc.dbo.pc p
    JOIN pc.dbo.product prod ON p.model = prod.model
WHERE prod.maker = ANY (SELECT DISTINCT prod.maker
                    FROM pc.dbo.product prod
                    WHERE EXISTS(SELECT *
                                 FROM pc.dbo.product
                                 WHERE type = 'Printer' AND maker = prod.maker))

SELECT screen,MAX(price) - MIN(price) AS PriceRange
FROM pc.dbo.laptop
GROUP BY screen


SELECT COUNT(sh.NAME)
FROM ships.dbo.CLASSES cl
    JOIN ships.dbo.SHIPS sh ON cl.CLASS = sh.CLASS
GROUP BY sh.CLASS

/*SELECT *
FROM ships.dbo.SHIPS sh
WHERE NOT EXISTS(SELECT * FROM ships.dbo.OUTCOMES WHERE NAME = sh.NAME)*/

SELECT sh.CLASS,MIN(YEAR(bat.DATE)) AS MIN_YEAR,MAX(YEAR(bat.DATE)) AS LAST_YEAR
FROM ships.dbo.SHIPS sh
    JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP
    JOIN ships.dbo.BATTLES bat ON out1.BATTLE = bat.NAME
GROUP BY sh.CLASS

SELECT sh.CLASS, COUNT(*) AS SunkCount
FROM ships.dbo.SHIPS sh
    JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP
WHERE out1.RESULT = 'sunk'
GROUP BY sh.CLASS

SELECT sh.CLASS, COUNT(*) sunkSipsCount
FROM ships.dbo.SHIPS sh
         JOIN (SELECT sh.CLASS, COUNT(sh.NAME) AS count
                FROM ships.dbo.OUTCOMES out1
                    RIGHT OUTER JOIN ships.dbo.SHIPS sh ON out1.SHIP = sh.NAME
                GROUP BY sh.CLASS
                HAVING COUNT(*) > 4) s ON sh.CLASS = s.CLASS
        JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP
WHERE out1.RESULT = 'sunk'
GROUP BY sh.CLASS


SELECT  cl.COUNTRY, SUM(sumW) / SUM(shCount) AS AVG_WEIGTH
FROM ships.dbo.CLASSES cl
    JOIN
     (SELECT cl.CLASS, (cl.DISPLACEMENT * shCount.ShipCount) AS SumW, shCount.ShipCount as shCount
      FROM ships.dbo.CLASSES cl
               JOIN (SELECT CLASS, COUNT(*) AS ShipCount
                     FROM ships.dbo.SHIPS
                     GROUP BY CLASS) shCount ON shCount.CLASS = cl.CLASS) newS ON cl.CLASS = newS.CLASS
GROUP BY COUNTRY

/*SELECT mvs.NAME, mvs.BIRTHDATE
FROM movies.dbo.MOVIESTAR mvs
    JOIN (SELECT STARNAME, MOVIETITLE,STUDIONAME
          FROM movies.dbo.STARSIN st
                   JOIN movies.dbo.MOVIE mv ON mv.TITLE = st.MOVIETITLE AND mv.YEAR = st.MOVIEYEAR
          ) u
WHERE
*/



SELECT DISTINCT prod.maker
FROM pc.dbo.product prod
    JOIN (SELECT maker,AVG(price) AS pcAVG
            FROM pc.dbo.product prod
                JOIN pc.dbo.pc ON prod.model = pc.model
            GROUP BY prod.maker) pc1 ON pc1.maker = prod.maker
    JOIN (SELECT maker,AVG(price) as lapAVG
            FROM pc.dbo.product prod
                JOIN pc.dbo.laptop ON prod.model = laptop.model
            GROUP BY prod.maker) lap1 ON lap1.maker = prod.maker
WHERE pc1.pcAVG <= lap1.lapAVG

SELECT prod.maker, pcAVG, lapMin
FROM pc.dbo.product prod
    JOIN (SELECT maker, prod.model, AVG(price) AS pcAVG
       FROM pc.dbo.pc pc1
                JOIN pc.dbo.product prod ON pc1.model = prod.model
       GROUP BY maker, prod.model) pcAvg ON pcAvg.model = prod.model
    JOIN (SELECT maker, MIN(price) as lapMin
            FROM pc.dbo.product prod
                JOIN pc.dbo.laptop lap ON prod.model = lap.model
            GROUP BY maker) lap ON prod.maker = lap.maker
WHERE lapMin > pcAVG

SELECT out1.BATTLE, cl.COUNTRY , COUNT(sh.NAME)
FROM ships.dbo.SHIPS sh
    JOIN ships.dbo.CLASSES cl ON sh.CLASS = cl.CLASS
    LEFT JOIN ships.dbo.OUTCOMES out1 ON out1.SHIP = sh.NAME
WHERE out1.BATTLE is not null
GROUP BY out1.BATTLE, cl.COUNTRY
HAVING COUNT(sh.NAME) >= 3

SELECT sh.NAME, COUNT(out1.BATTLE)
FROM ships.dbo.SHIPS sh
    LEFT OUTER JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP AND RESULT = 'damaged'
GROUP BY NAME

SELECT cl.CLASS , cl.COUNTRY,MIN(sh.LAUNCHED) AS FirstLaunched
FROM ships.dbo.CLASSES cl
    JOIN ships.dbo.SHIPS sh ON sh.CLASS = cl.CLASS
GROUP BY cl.CLASS, cl.COUNTRY

SELECT cl.COUNTRY, COUNT(sh.NAME) AS ShipCout/*, COUNT(sh2.NAME)*/
FROM ships.dbo.CLASSES cl
    LEFT JOIN ships.dbo.SHIPS sh ON sh.CLASS = cl.CLASS
    LEFT JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP

/*    LEFT JOIN ships.dbo.SHIPS sh2 ON sh2.CLASS = cl.CLASS
    LEFT JOIN ships.dbo.OUTCOMES out2 ON sh2.NAME = out2.SHIP AND out2.RESULT = 'sunk'*/
GROUP BY cl.COUNTRY

SELECT c.COUNTRY, COUNT(s.NAME), COUNT(o.RESULT)
FROM ships.dbo.CLASSES c
    LEFT JOIN ships.dbo.SHIPS s ON c.CLASS = s.CLASS
    LEFT JOIN ships.dbo.OUTCOMES o ON o.SHIP = s.NAME AND o.RESULT = 'sunk'
GROUP BY c.COUNTRY

SELECT cl.CLASS, sh.NAME, out1.RESULT
FROM ships.dbo.CLASSES cl
    JOIN ships.dbo.SHIPS sh ON sh.CLASS = cl.CLASS
    LEFT JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP AND out1.RESULT = 'ok'

SELECT sh.CLASS, COUNT(DISTINCT sh.NAME)
FROM ships.dbo.SHIPS sh
    LEFT JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP AND out1.RESULT = 'ok'
GROUP BY sh.CLASS
HAVING COUNT(DISTINCT sh.NAME) >= 3