import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../data/data.csv")

plt.figure(figsize=(12, 7))

plt.plot(
    df["Size"],
    df["VecMs"],
    marker="o",
    linewidth=2,
    label="Vec"
)

plt.plot(
    df["Size"],
    df["StdVectorMs"],
    marker="s",
    linewidth=2,
    label="std::vector"
)

plt.plot(
    df["Size"],
    df["LinkedListMs"],
    marker="^",
    linewidth=2,
    label="LinkedList"
)

plt.xlabel("Number of Append Operations")
plt.ylabel("Execution Time (ms)")

plt.title("Append Performance Comparison")

plt.legend()

plt.grid(
    True,
    linestyle="--",
    alpha=0.5
)

plt.tight_layout()

plt.savefig(
    "append_runtime.png",
    dpi=300
)

plt.show()

capacity_df = pd.read_csv(
    "../data/capacity_growth.csv"
)

std_capacity_df = pd.read_csv(
    "../data/std_capacity_growth.csv"
)

plt.figure(figsize=(12, 7))

plt.step(
    capacity_df["Size"],
    capacity_df["Capacity"],
    where="post",
    linewidth=2,
    label="Vec"
)

plt.step(
    std_capacity_df["Size"],
    std_capacity_df["Capacity"],
    where="post",
    linewidth=2,
    label="std::vector"
)

plt.xlabel("Elements Stored")
plt.ylabel("Capacity")

plt.title("Capacity Growth Comparison")

plt.legend()

plt.grid(
    True,
    linestyle="--",
    alpha=0.5
)

plt.tight_layout()

plt.savefig(
    "capacity_growth.png",
    dpi=300
)