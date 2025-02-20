package main

import (
	"database/sql"
	"fmt"
	"log"
	"os"

	"github.com/joho/godotenv"
	"github.com/labstack/echo/v4"
	"github.com/labstack/echo/v4/middleware"
	_ "github.com/lib/pq"
)

type function_s struct {
	Category string
	Name     string
	Header   string
	Body     string
	Doc      string
}

func query_search_match(userInput string, db *sql.DB) *sql.Rows {
	if userInput == "" {
		return nil
	}
	query_string := "SELECT * FROM functions.function WHERE name ~* $1 ORDER BY name"
	reg := ".*" + userInput + ".*"
	res, err := db.Query(query_string, reg)
	if err != nil {
		log.Fatal(err)
	}
	return res
}

func query_function(name string, db *sql.DB) *sql.Rows {
	if name == "" {
		return nil
	}
	query_string := "SELECT * FROM functions.function WHERE name = $1 LIMIT 1"
	res, err := db.Query(query_string, name)
	if err != nil {
		log.Fatal(err)
	}
	return res
}

func init_db() *sql.DB {
	err := godotenv.Load()
	if err != nil {
		log.Fatal("Error loading .env file")
	}
	dbname := os.Getenv("POSTGRES_DB")
	username := os.Getenv("POSTGRES_USER")
	password := os.Getenv("POSTGRES_PASSWORD")
	host := os.Getenv("POSTGRES_HOST")
	port := os.Getenv("POSTGRES_PORT")
	conn := fmt.Sprintf("user=%s password=%s dbname=%s host=%s port=%s sslmode=disable", username, password, dbname, host, port)
	db, err := sql.Open("postgres", conn)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Connected to database")
	return db
}

func main() {
	db := init_db()
	e := echo.New()
	e.Use(middleware.CORS())
	e.POST("/queryFunctions", func(c echo.Context) error {
		var matches *sql.Rows = query_search_match(c.QueryParam("input"), db)
		if matches == nil {
			return c.JSON(200, []string{})
		}
		var functions_name []string
		for matches.Next() {
			var function function_s
			err := matches.Scan(&function.Category, &function.Name, &function.Header, &function.Body, &function.Doc)
			if err != nil {
				log.Fatal(err)
			}
			functions_name = append(functions_name, function.Name)
		}
		defer matches.Close()
		return c.JSON(200, functions_name)
	})
	e.POST("/getFunction", func(c echo.Context) error {
		res := query_function(c.QueryParam("input"), db)
		if res == nil {
			return c.JSON(200, nil)
		}
		var function *function_s = new(function_s)
		if !res.Next() {
			return c.JSON(200, nil)
		}
		err := res.Scan(&function.Category, &function.Name, &function.Header, &function.Body, &function.Doc)
		if err != nil {
			log.Fatal(err)
		}
		defer res.Close()
		return c.JSON(200, function)
	})
	e.Logger.Fatal(e.Start("localhost:1323"))
}
