# Use an official Ubuntu as a base image
FROM ubuntu:22.04
ENV LANG=C.UTF-8
ENV LC_ALL=C.UTF-8

ARG USER_NAME=cmaybe
ARG GROUP_NAME=bear
ARG PROJECT_NAME=bear-atm

# Setup timezone
RUN echo 'Etc/UTC' > /etc/timezone \
    && ln -s /usr/share/zoneinfo/Etc/UTC /etc/localtime \
    && apt-get update \
    && apt-get -y -q --no-install-recommends install \
        tzdata \
    && apt-get clean

# Install dependencies
RUN apt-get update && apt-get install -y \
    apt-utils \
    bash-completion \
    cmake \
	clang-format \
    g++ \
    git \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Add user info
ARG USER_UID=1000
ARG USER_GID=1000
RUN groupadd --gid ${USER_GID} ${GROUP_NAME} 

RUN useradd --create-home --shell /bin/bash \
    --uid ${USER_UID} --gid ${USER_GID} ${USER_NAME} \
    # Possible security risk
    && echo "${USER_NAME}:${GROUP_NAME}" | sudo chpasswd \
    && echo "${USER_NAME} ALL=(ALL) NOPASSWD:ALL" > "/etc/sudoers.d/${USER_NAME}"

# Make workspace 
RUN mkdir -p /home/${USER_NAME}/${PROJECT_NAME} \
    && chown -R ${USER_NAME}:${GROUP_NAME} /home/${USER_NAME}
ENV HOME=/home/${USER_NAME}

RUN echo "export USER=${USER_NAME}" >> ${HOME}/.bashrc \
    && echo "export GROUP=${GROUP_NAME}" >> ${HOME}/.bashrc \
    && echo "export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH" >> ${HOME}/.bashrc 

# Shell
USER ${USER_NAME}
WORKDIR /home/${USER_NAME}/${PROJECT_NAME}
ENV SHELL="/bin/bash"
