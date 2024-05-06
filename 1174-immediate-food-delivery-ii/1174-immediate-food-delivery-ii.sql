WITH cte AS (
    SELECT
        customer_id,
        order_date,
        customer_pref_delivery_date,
        RANK() OVER (PARTITION BY customer_id ORDER BY order_date) AS rk
    FROM
        Delivery
)

SELECT
    ROUND(
        100.0 * SUM(
            CASE
                WHEN order_date = customer_pref_delivery_date THEN 1
                ELSE 0
            END
        ) / COUNT(*),
        2
    ) AS immediate_percentage
FROM
    cte
WHERE
    rk = 1;