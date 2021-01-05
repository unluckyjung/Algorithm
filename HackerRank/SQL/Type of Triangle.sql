SELECT CASE
        WHEN GREATEST(A, B, C) * 2 >= A + B + C 
            THEN 'Not A Triangle'
        WHEN A = B AND B = C
            THEN 'Equilateral'
        WHEN A = B OR B = C OR C = A
            THEN 'Isosceles'
        ELSE 'Scalene'  
    END
FROM TRIANGLES;