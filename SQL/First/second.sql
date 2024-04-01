
/*SELECT MOVIESTAR.NAME
FROM movies.dbo.MOVIESTAR
WHERE NAME NOT IN (SELECT NAME FROM movies.dbo.MOVIEEXEC )*/

/*SELECT TITLE
FROM movies.dbo.MOVIE
WHERE LENGTH > (SELECT LENGTH FROM movies.dbo.MOVIE WHERE TITLE = 'Star Wars')*/

/*SELECT DISTINCT maker
FROM pc.dbo.product prod
    JOIN pc.dbo.pc p ON p.model = prod.model
WHERE p.speed >= 500*/

/*SELECT model
FROM pc.dbo.printer
WHERE price  >= ALL (SELECT price FROM pc.dbo.printer)*/

/*SELECT model
FROM pc.dbo.laptop
WHERE speed < ANY (SELECT speed FROM pc.dbo.pc)*/

/*SELECT DISTINCT u.model
FROM (SELECT price,model FROM pc.dbo.pc
    UNION
    SELECT price,model FROM pc.dbo.laptop
    UNION
    SELECT price,model FROM pc.dbo.printer) u
WHERE u.price >= ALL (SELECT price FROM pc.dbo.pc
                        UNION
                        SELECT price FROM pc.dbo.laptop
                        UNION
                        SELECT price FROM pc.dbo.printer)*/

/*SELECT DISTINCT prod.maker
FROM pc.dbo.product prod
    JOIN pc.dbo.printer prin ON prin.model = prod.model
WHERE prin.color = 'y' AND prin.price <= ALL (SELECT price FROM pc.dbo.printer WHERE color = 'y')*/

/*SELECT prod.maker
FROM pc.dbo.product prod
    JOIN pc.dbo.pc pc1 ON pc1.model = prod.model
WHERE pc1.speed >= ALL (SELECT pc2.speed FROM pc.dbo.pc pc2 WHERE pc1.ram = pc2.ram)
    AND pc1.ram <= ALL (SELECT ram FROM pc.dbo.pc)*/

/*SELECT DISTINCT cl.COUNTRY
FROM ships.dbo.CLASSES cl
WHERE cl.NUMGUNS >= ALL (SELECT NUMGUNS FROM ships.dbo.CLASSES)*/

/*SELECT DISTINCT cl.CLASS
FROM ships.dbo.CLASSES cl
    JOIN ships.dbo.SHIPS sh ON sh.CLASS = cl.CLASS
WHERE EXISTS(SELECT * FROM ships.dbo.OUTCOMES out WHERE out.SHIP = sh.NAME AND out.RESULT = 'sunk')*/

/*SELECT NAME
FROM ships.dbo.SHIPS
WHERE SHIPS.CLASS IN (SELECT CLASSES.CLASS FROM ships.dbo.CLASSES WHERE BORE = 16)*/

/*SELECT out.BATTLE
FROM ships.dbo.OUTCOMES out
WHERE out.SHIP IN (SELECT NAME FROM ships.dbo.SHIPS WHERE CLASS = 'Kongo')*/

/*SELECT sh.NAME
FROM ships.dbo.SHIPS sh
    JOIN ships.dbo.CLASSES cl ON sh.CLASS = cl.CLASS
WHERE cl.NUMGUNS >= ALL (SELECT cl2.NUMGUNS FROM ships.dbo.CLASSES cl2 WHERE cl2.BORE = cl.BORE)*/

/*#######################week 4###################*/

/*SELECT mv.TITLE,mv.YEAR,mv.STUDIONAME,st.ADDRESS
FROM movies.dbo.MOVIE mv
    FULL JOIN movies.dbo.STUDIO st ON  mv.STUDIONAME = st.NAME
WHERE mv.LENGTH > 120*/

/*SELECT mv.STUDIONAME, st.STARNAME
FROM movies.dbo.MOVIE mv
    JOIN movies.dbo.STARSIN st ON mv.TITLE = st.MOVIETITLE AND mv.YEAR = st.MOVIEYEAR
ORDER BY mv.STUDIONAME*/

/*SELECT mv.TITLE ,ex.NAME
FROM movies.dbo.MOVIE mv
    JOIN movies.dbo.STARSIN st ON mv.TITLE = st.MOVIETITLE AND mv.YEAR = st.MOVIEYEAR
    JOIN movies.dbo.MOVIEEXEC ex ON mv.PRODUCERC# = ex.CERT#
WHERE st.STARNAME = 'Harrison Ford'*/

/*SELECT ms.NAME
FROM movies.dbo.STARSIN st
    JOIN movies.dbo.MOVIE mv ON mv.TITLE = st.MOVIETITLE AND mv.YEAR = st.MOVIEYEAR
    JOIN movies.dbo.MOVIESTAR ms ON ms.NAME = st.STARNAME
WHERE ms.GENDER = 'f' AND mv.STUDIONAME = 'MGM'*/

/*SELECT ex.NAME, mv.TITLE
FROM movies.dbo.MOVIEEXEC ex
    JOIN movies.dbo.MOVIE mv ON mv.PRODUCERC# = ex.CERT#
WHERE ex.CERT# = ANY (SELECT mv2.PRODUCERC# FROM movies.dbo.MOVIE mv2 WHERE mv2.TITLE = 'Star Wars')
  AND mv.TITLE != 'Star Wars'*/

/*SELECT NAME
FROM movies.dbo.MOVIESTAR
    LEFT OUTER JOIN movies.dbo.STARSIN ON STARNAME = NAME
WHERE STARNAME is NULL*/

/*SELECT prod.maker,prod.type,prod.model
FROM pc.dbo.product prod
    LEFT JOIN (SELECT model,price FROM pc.dbo.pc
        UNION
        SELECT model,price FROM pc.dbo.laptop
        UNION
        SELECT model,price FROM pc.dbo.printer) u ON u.model = prod.model
WHERE u.price is NULL*/

/*SELECT sh.NAME, cl.COUNTRY, cl.NUMGUNS, sh.LAUNCHED
FROM ships.dbo.SHIPS sh
    JOIN ships.dbo.CLASSES cl ON sh.CLASS = cl.CLASS*/

/*SELECT sh.NAME
FROM ships.dbo.SHIPS sh
    JOIN ships.dbo.OUTCOMES out1 ON sh.NAME = out1.SHIP
    JOIN ships.dbo.BATTLES bat ON out1.BATTLE = bat.NAME
WHERE YEAR(bat.DATE) = 1942*/

SELECT sh.NAME, cl.COUNTRY
FROM ships.dbo.SHIPS sh
    LEFT JOIN ships.dbo.CLASSES cl ON sh.CLASS = cl.CLASS
    LEFT JOIN ships.dbo.OUTCOMES out ON sh.NAME = out.SHIP
WHERE out.RESULT is NULL
