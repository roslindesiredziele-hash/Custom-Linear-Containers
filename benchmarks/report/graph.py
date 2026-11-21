import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.axes_grid1.inset_locator import inset_axes

# ==================================================
# Append Runtime Graph
# ==================================================

df = pd.read_csv("../data/data.csv")

fig, ax = plt.subplots(figsize=(12, 7))

ax.plot(
    df["Size"],
    df["VecMs"],
    marker="o",
    linewidth=2,
    label="Vec"
)

ax.plot(
    df["Size"],
    df["StdVectorMs"],
    marker="s",
    linewidth=2,
    label="std::vector"
)

ax.plot(
    df["Size"],
    df["LinkedListMs"],
    marker="^",
    linewidth=2,
    label="LinkedList"
)

ax.set_xlabel("Number of Append Operations")
ax.set_ylabel("Execution Time (ms)")

ax.set_title(
    "Append Performance Comparison"
)

ax.legend()

ax.grid(
    True,
    linestyle="--",
    alpha=0.5
)

# --------------------------------------------------
# Inset: Vec vs std::vector
# --------------------------------------------------

axins = inset_axes(
    ax,
    width="40%",
    height="40%",
    loc="upper left"
)

axins.plot(
    df["Size"],
    df["VecMs"],
    marker="o",
    linewidth=2,
    label="Vec"
)

axins.plot(
    df["Size"],
    df["StdVectorMs"],
    marker="s",
    linewidth=2,
    label="std::vector"
)

# Zoom into region where differences matter
axins.set_xlim(0, 120000)
axins.set_ylim(0, 1.2)

axins.set_title(
    "Zoom: Vec vs std::vector",
    fontsize=8
)

axins.grid(
    True,
    alpha=0.4
)

axins.legend(
    fontsize=7
)

fig.subplots_adjust(
    left=0.10,
    right=0.97,
    bottom=0.10,
    top=0.92
)

plt.savefig(
    "append_runtime.png",
    dpi=300,
    bbox_inches="tight"
)

plt.close(fig)

# ==================================================
# Capacity Growth Comparison
# ==================================================

capacity_df = pd.read_csv(
    "../data/capacity_growth.csv"
)

std_capacity_df = pd.read_csv(
    "../data/std_capacity_growth.csv"
)

fig, ax = plt.subplots(figsize=(12, 7))

ax.step(
    capacity_df["Size"],
    capacity_df["Capacity"],
    where="post",
    linewidth=3,
    linestyle="--",
    color="tab:blue",
    label="Vec"
)

ax.step(
    std_capacity_df["Size"],
    std_capacity_df["Capacity"],
    where="post",
    linewidth=2,
    color="tab:orange",
    label="std::vector"
)

ax.set_xlabel("Elements Stored")
ax.set_ylabel("Capacity")

ax.set_title(
    "Capacity Growth Comparison"
)

ax.legend()

ax.grid(
    True,
    linestyle="--",
    alpha=0.5
)

# --------------------------------------------------
# Inset: Initial Difference
# --------------------------------------------------

axins = inset_axes(
    ax,
    width="35%",
    height="35%",
    loc="upper left"
)

axins.step(
    capacity_df["Size"],
    capacity_df["Capacity"],
    where="post",
    linewidth=2,
    linestyle="--",
    color="tab:blue"
)

axins.step(
    std_capacity_df["Size"],
    std_capacity_df["Capacity"],
    where="post",
    linewidth=2,
    color="tab:orange"
)

axins.set_xlim(0, 3)
axins.set_ylim(0, 5)

axins.set_title(
    "Initial Growth",
    fontsize=8
)

axins.grid(
    True,
    alpha=0.4
)

axins.legend(
    ["Vec", "std::vector"],
    fontsize=7
)

fig.subplots_adjust(
    left=0.10,
    right=0.97,
    bottom=0.10,
    top=0.92
)

plt.savefig(
    "capacity_growth.png",
    dpi=300,
    bbox_inches="tight"
)

plt.close(fig)

print("Graphs generated successfully.")