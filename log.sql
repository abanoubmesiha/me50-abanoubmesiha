-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE street = "Chamberlin Street" AND day = 28;

id | year | month | day | street | description
295 | 2020 | 7 | 28 | Chamberlin Street | Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

SELECT * FROM interviews WHERE day = 28 AND month = 7;

id | name | year | month | day | transcript
158 | Jose | 2020 | 7 | 28 | “Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
159 | Eugene | 2020 | 7 | 28 | “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”

160 | Barbara | 2020 | 7 | 28 | “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.

161 | Ruth | 2020 | 7 | 28 | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- According to Ruth, Suspect left in a car between 10:15am and 10:25am

162 | Eugene | 2020 | 7 | 28 | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- According to Eugene, Suspect Withdraw money before 10:15am

163 | Raymond | 2020 | 7 | 28 | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- According to Raymond, Suspect will leave out of town in the earlist flight.
-- According to Raymond, Suspect made a less than one minute call.

SELECT * FROM courthouse_security_logs WHERE year = 2020 AND day = 28 AND month = 7 AND activity = "exit" AND hour = 10 AND minute > 15 AND minute < 45;

id | year | month | day | hour | minute | activity | license_plate
260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55
268 | 2020 | 7 | 28 | 10 | 35 | exit | 1106N58

-- Get suspects according to license_plate

SELECT * FROM people WHERE license_plate IN ("5P2BI95", "94KL13X", "6P58WS2", "4328GD8", "G412CB7", "L93JTIZ", "322W7JE", "0NTHK55", "1106N58");

id | name | phone_number | passport_number | license_plate
221103 | Patrick | (725) 555-4692 | 2963008352 | 5P2BI95
243696 | Amber | (301) 555-4174 | 7526138472 | 6P58WS2
396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE
560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X

-- Some of these suspects ( who left the scene in a car ) have called our target call or received it.

SELECT * FROM phone_calls INNER JOIN people ON people.phone_number = phone_calls.caller WHERE year = 2020 AND day = 28 AND month = 7 AND duration <= 60 AND caller in ("(725) 555-4692","(301) 555-4174","(829) 555-5269","(130) 555-0289","(286) 555-6063","(389) 555-5198","(770) 555-1861","(499) 555-9472","(367) 555-5533");

id | caller | receiver | year | month | day | duration | id | name | phone_number | passport_number | license_plate
221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51 | 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36 | 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50 | 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43 | 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49 | 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE

SELECT * FROM phone_calls INNER JOIN people ON people.phone_number = phone_calls.caller WHERE year = 2020 AND day = 28 AND month = 7 AND duration <= 60 AND receiver in ("(725) 555-4692","(301) 555-4174","(829) 555-5269","(130) 555-0289","(286) 555-6063","(389) 555-5198","(770) 555-1861","(499) 555-9472","(367) 555-5533"); ;

id | caller | receiver | year | month | day | duration | id | name | phone_number | passport_number | license_plate
234 | (609) 555-5876 | (389) 555-5198 | 2020 | 7 | 28 | 60 | 561160 | Kathryn | (609) 555-5876 | 6121106406 | 4ZY7I8T

-- Get the suspects who used the atm AND according to license_plate results above

SELECT * FROM atm_transactions INNER JOIN bank_accounts ON atm_transactions.account_number=bank_accounts.account_number INNER JOIN people ON bank_accounts.person_id=people.id WHERE atm_location = "Fifer Street" AND year = 2020 AND day = 28 AND month = 7 AND transaction_type = "withdraw" AND person_id in ("221103","243696","396669","398010","449774","467400","514354","560886","686048");
-- INNER JOIN passengers ON people.passport_number=passengers.passport_number

id | account_number | year | month | day | atm_location | transaction_type | amount | account_number | person_id | creation_year | id | name | phone_number | passport_number | license_plate
267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50 | 49610011 | 686048 | 2010 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35 | 26013199 | 514354 | 2012 | 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE
288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20 | 25506511 | 396669 | 2014 | 396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48 | 28500762 | 467400 | 2014 | 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60 | 76054385 | 449774 | 2015 | 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58

-- Five suspects Ernest, Russell, Elizabeth, Danielle, and Madison
-- Get who made the target call, Ernest, Russell, and Madison
-- Pick the one who was on London flight

SELECT * FROM airports WHERE city = "Fiftyville";

id | abbreviation | full_name | city
8 | CSF | Fiftyville Regional Airport | Fiftyville

SELECT * FROM flights WHERE origin_airport_id = 8 AND year = 2020 AND day = 29 AND month = 7;

id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0
23 | 8 | 11 | 2020 | 7 | 29 | 12 | 15
36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20
43 | 8 | 1 | 2020 | 7 | 29 | 9 | 30
53 | 8 | 9 | 2020 | 7 | 29 | 15 | 20

-- Earlest flight is London
SELECT * FROM airports
WHERE id = 4;

id | abbreviation | full_name | city
4 | LHR | Heathrow Airport | London

SELECT * FROM flights WHERE destination_airport_id = 4 AND year = 2020 AND day = 29 AND month = 7;

id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20


SELECT * FROM passengers INNER JOIN people ON passengers.passport_number = people.passport_number WHERE flight_id = 36;

flight_id | passport_number | seat | id | name | phone_number | passport_number | license_plate
36 | 7214083635 | 2A | 953679 | Doris | (066) 555-9701 | 7214083635 | M51FA04
36 | 1695452385 | 3B | 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
36 | 5773159633 | 4A | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
36 | 1540955065 | 5C | 651714 | Edward | (328) 555-1152 | 1540955065 | 130LD9Z
36 | 8294398571 | 6C | 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
36 | 1988161715 | 6D | 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
36 | 9878712108 | 7A | 395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN
36 | 8496433585 | 7B | 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8

-- Now Ernest and Madison are suspects, they are both traveled to london, let's check who they called.

-- Madison Called James

SELECT * FROM people WHERE phone_number = "(676) 555-6554";

id | name | phone_number | passport_number | license_plate
250277 | James | (676) 555-6554 | 2438825627 | Q13SVG6

-- Ernest Called Berthold which doesn't have passport_number so he didn't leave the town

SELECT * FROM people WHERE phone_number = "(375) 555-8161";

id | name | phone_number | passport_number | license_plate
864400 | Berthold | (375) 555-8161 |  | 4V16VO0