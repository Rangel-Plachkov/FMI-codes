SELECT ADDRESS
FROM movies.dbo.STUDIO
WHERE NAME = 'MGM'

SELECT BIRTHDATE
FROM movies.dbo.MOVIESTAR
Where NAME = 'Sandra Bullock'

SELECT STARNAME
FROM movies.dbo.STARSIN
WHERE MOVIETITLE LIKE '%Empire%' AND MOVIEYEAR >= 1980

SELECT NAME
FROM movies.dbo.MOVIEEXEC
WHERE NETWORTH >= 10000000

SELECT NAME
FROM movies.dbo.MOVIESTAR
WHERE ADDRESS = 'Malibu' OR GENDER = 'M'

SELECT speed AS MHz ,hd AS GB
FROM pc.dbo.pc
WHERE price <= 1200

SELECT model,price * 1.1 as DOLARS
FROM pc.dbo.laptop
ORDER BY price

SELECT model,hd,screen
FROM pc.dbo.laptop
WHERE price >= 1000

SELECT model
FROM pc.dbo.printer
where color = 'y'

SELECT model,speed,hd
FROM pc.dbo.pc
WHERE (cd like '12x' OR cd like '16x')
AND price <= 2000

SELECT code,model, (speed + ram + 10*screen) AS raiting
FROM pc.dbo.laptop
ORDER BY raiting desc , code desc 

SELECT CLASS,COUNTRY
FROM ships.dbo.CLASSES
WHERE NUMGUNS <= 10

SELECT NAME AS shipName
FROM ships.dbo.SHIPS
WHERE LAUNCHED <= 1918

SELECT SHIP,BATTLE
FROM ships.dbo.OUTCOMES
WHERE RESULT = 'sunk'

SELECT NAME
FROM ships.dbo.SHIPS
WHERE NAME = CLASS

SELECT NAME
FROM ships.dbo.SHIPS
WHERE NAME like 'R%'

SELECT NAME
FROM ships.dbo.SHIPS
WHERE NAME like '% %' AND NOT NAME like '% % %'

Select NAME
FROM movies.dbo.MOVIESTAR JOIN movies.dbo.STARSIN ON MOVIESTAR.NAME = STARSIN.STARNAME
WHERE GENDER = 'M' AND STARSIN.MOVIETITLE like 'Terms of Endearment'

Select DISTINCT NAME
From movies.dbo.MOVIESTAR
    JOIN movies.dbo.STARSIN ON MOVIESTAR.NAME = STARSIN.STARNAME
    JOIN movies.dbo.MOVIE ON STARSIN.MOVIETITLE = MOVIE.TITLE
WHERE MOVIE.STUDIONAME='MGM'
  AND MOVIEYEAR = 1995

SELECT m1.TITLE
FROM movies.dbo.MOVIE m1
JOIN movies.dbo.MOVIE m2 ON m2.TITLE = 'Star Wars'
WHERE m1.LENGTH > m2.LENGTH

SELECT DISTINCT p.maker,l.speed
FROM pc.dbo.laptop l
JOIN pc.dbo.product p ON l.model = p.model
WHERE hd > 9

SELECT u.model, u.price
FROM pc.dbo.product p
JOIN (SELECT model, price FROM pc.dbo.pc
    UNION
    SELECT model, price FROM pc.dbo.laptop
    UNION
    SELECT model, price FROM pc.dbo.printer) u ON p.model = u.model
Where p.maker = 'B'
ORDER BY price desc

SELECT DISTINCT p1.hd
FROM pc.dbo.pc p1
    JOIN pc.dbo.pc p2 ON p2.cd = p1.cd
WHERE p1.model != p2.model

SELECT p1.model, p2.model
FROM pc.dbo.pc p1
    JOIN pc.dbo.pc p2 ON p1.model != p2.model
WHERE p1.speed = p2.speed AND p1.hd = p2.hd AND p1.model < p2.model

SELECT DISTINCT prod1.maker
FROM pc.dbo.product prod1
    JOIN pc.dbo.product prod2 ON prod1.maker = prod2.maker
    JOIN pc.dbo.pc pc1 ON pc1.model = prod1.model
    JOIN pc.dbo.pc pc2 ON pc2.model = prod2.model
WHERE pc1.speed >= 500 AND pc2.speed >= 500 AND pc1.code != pc2.code

SELECT sh.NAME
FROM ships.dbo.SHIPS sh
    JOIN ships.dbo.CLASSES cl ON cl.CLASS = sh.CLASS
WHERE cl.DISPLACEMENT > 35000

SELECT sh.NAME, cl.DISPLACEMENT
FROM ships.dbo.CLASSES cl
    JOIN ships.dbo.SHIPS sh ON sh.CLASS = cl.CLASS
    JOIN ships.dbo.OUTCOMES out ON out.BATTLE = 'Guadalcanal'
WHERE sh.NAME = out.SHIP

SELECT cl1.COUNTRY
FROM ships.dbo.CLASSES cl1
    JOIN ships.dbo.CLASSES cl2 ON cl1.COUNTRY = cl2.COUNTRY
WHERE cl1.TYPE = 'bb' AND cl2.TYPE = 'bc'

SELECT DISTINCT out1.SHIP
FROM ships.dbo.OUTCOMES out1
    JOIN ships.dbo.OUTCOMES out2 ON out2.SHIP = out1.SHIP
    JOIN ships.dbo.BATTLES bat1 ON bat1.NAME = out1.BATTLE
    JOIN ships.dbo.BATTLES bat2 ON bat2.NAME = out2.BATTLE
WHERE bat1.DATE < bat2.DATE AND out1.RESULT = 'damaged'
