# importing need libraries 
import sqlite3
import pandas as pd 
import connectLocalSQL as createSQL
import os
from credentials import openAIKey
from langchain.agents import create_sql_agent
from langchain.agents.agent_toolkits import SQLDatabaseToolkit
from langchain.sql_database import SQLDatabase
from langchain.llms.openai import OpenAI
from langchain.agents import AgentExecutor
import tkinter as tk
import tkinter.ttk as ttk


# creating a sqlite database
db_file = 'sample.db'
sql_file = 'sampleDatabase.sql'

# creating a sqlite database
createSQL.create_sqlite_database(db_file, sql_file)

# fetching the openAIkey 
os.environ['OPENAI_API_KEY'] = openAIKey

db = SQLDatabase.from_uri("sqlite:///./sample.db")
llm = OpenAI()
toolkit = SQLDatabaseToolkit(db=db,llm=llm)

agent_executor = create_sql_agent(
    llm=OpenAI(temperature=0),
    toolkit=toolkit,
    verbose=True
)

# Create the UI window
root = tk.Tk()
root.title("Chat with your Tabular Data")

# Create the text entry widget
entry = ttk.Entry(root, font=("Arial", 14))
entry.pack(padx=20, pady=20, fill=tk.X)

# Create the button callback
def on_click():
    # Get the query text from the entry widget
    query = entry.get()

    # Run the query using the agent executor
    result = agent_executor.run(query)

    # Display the result in the text widget
    text.delete("1.0", tk.END)
    text.insert(tk.END, result)

# Create the button widget
button = ttk.Button(root, text="Chat", command=on_click)
button.pack(padx=20, pady=20)

# Create the text widget to display the result
text = tk.Text(root, height=10, width=60, font=("Arial", 14))
text.pack(padx=20, pady=20)

# Start the UI event loop
root.mainloop()
