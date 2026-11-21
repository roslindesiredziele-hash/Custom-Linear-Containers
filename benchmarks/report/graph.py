import pandas as pd
import matplotlib.pyplot as plt

csv_file = "../data/data.csv"

df = pd.read_csv(csv_file)

# Linear scale graph
plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["VecMs"],
    marker="o",
    label="Vec"
)

plt.plot(
    df["Size"],
    df["StdVectorMs"],
    marker="s",
    label="std::vector"
)

plt.plot(
    df["Size"],
    df["LinkedListMs"],
    marker="^",
    label="LinkedList"
)

plt.xlabel("Number of Append Operations")
plt.ylabel("Time (ms)")
plt.title("Append Performance Comparison")

plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig("runtime.png")

plt.close()

# Log-log graph
plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["VecMs"],
    marker="o",
    label="Vec"
)

plt.plot(
    df["Size"],
    df["StdVectorMs"],
    marker="s",
    label="std::vector"
)

plt.plot(
    df["Size"],
    df["LinkedListMs"],
    marker="^",
    label="LinkedList"
)

plt.xscale("log")
plt.yscale("log")

plt.xlabel("Number of Append Operations (log scale)")
plt.ylabel("Time (ms, log scale)")

plt.title(
    "Append Performance Comparison (Log-Log)"
)

plt.legend()

plt.grid(
    True,
    which="both"
)

plt.tight_layout()

plt.savefig(
    "runtime_logarithmic.png"
)

plt.close()

print("Graphs generated successfully.")