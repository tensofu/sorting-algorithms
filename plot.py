import pandas as pd
import matplotlib.pyplot as plt

# Read in data/data.csv into a Dataframe
df = pd.read_csv("data/Benchmarks_Sorts.csv")

# Scatter plot of total time
plt.figure(figsize=(10, 6))
for algorithm in df['algorithm'].unique():
    subset = df[df['algorithm'] == algorithm]
    plt.scatter(subset['input_size'], subset['total_time'], label=algorithm)
plt.xlabel('Input Size')
plt.ylabel('Total Time (seconds)')
plt.title('Total Trial Times for Different Algorithms')
plt.legend()
plt.grid(True)
plt.savefig('images/total_time_scatter.png')
plt.clf() 

# Line plot of total time
plt.figure(figsize=(10, 6))
for algorithm in df['algorithm'].unique():
    subset = df[df['algorithm'] == algorithm]
    avg_times = subset.groupby('input_size')['total_time'].mean()
    plt.plot(avg_times.index, avg_times.values, marker='o', linestyle='-', label=algorithm)
plt.xlabel('Input Size')
plt.ylabel('Average Total Time (seconds)')
plt.title('Average Total Trial Times for Different Algorithms')
plt.legend()
plt.grid(True)
plt.savefig('images/average_total_time_curve.png')
plt.clf() 

# Scatter plot of times per element 
plt.figure(figsize=(10, 6))
for algorithm in df['algorithm'].unique():
    subset = df[df['algorithm'] == algorithm]
    plt.scatter(subset['input_size'], subset['time_per_element'], label=algorithm)
plt.xlabel('Input Size')
plt.ylabel('Time Per Element (seconds)')
plt.title('Time Per Array Element for Different Algorithms')
plt.legend()
plt.grid(True)
plt.savefig('images/time_per_element_scatter.png')
plt.clf() 

# Line plot of times per element  
plt.figure(figsize=(10, 6))
for algorithm in df['algorithm'].unique():
    subset = df[df['algorithm'] == algorithm]
    avg_times_per_element = subset.groupby('input_size')['time_per_element'].mean()
    plt.plot(avg_times_per_element.index, avg_times_per_element.values, marker='o', linestyle='-', label=algorithm)
plt.xlabel('Input Size')
plt.ylabel('Average Time Per Element (seconds)')
plt.title('Average Time Per Array Element for Different Algorithms')
plt.legend()
plt.grid(True)
plt.savefig('images/average_time_per_element_curve.png')
plt.clf()
