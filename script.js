// ============================================
// Enhanced File Explorer Script
// ============================================

class FileExplorer {
  constructor() {
    this.currentPath = [];
    this.selectedCard = null;
    this.searchQuery = '';
    this.allFiles = [];
    this.init();
  }

  init() {
    this.setupEventListeners();
    this.loadFileStructure();
    this.setupTheme();
    this.setupScrollTop();
  }

  // ============================================
  // EVENT LISTENERS SETUP
  // ============================================

  setupEventListeners() {
    // Search functionality
    const searchInput = document.getElementById('search');
    const clearBtn = document.getElementById('clearSearch');
    
    searchInput?.addEventListener('input', (e) => this.handleSearch(e));
    clearBtn?.addEventListener('click', () => this.clearSearch());

    // Keyboard navigation
    document.addEventListener('keydown', (e) => this.handleKeyboardNav(e));

    // Theme toggle
    const themeSwitch = document.getElementById('themeSwitch');
    themeSwitch?.addEventListener('change', () => this.toggleTheme());

    // Menu toggle for mobile
    const menuToggle = document.getElementById('menuToggle');
    menuToggle?.addEventListener('click', () => this.toggleSidebar());

    // Home link
    const homeLink = document.getElementById('homeLink');
    homeLink?.addEventListener('click', (e) => {
      e.preventDefault();
      this.currentPath = [];
      this.renderContent();
    });
  }

  // ============================================
  // SEARCH FUNCTIONALITY (ENHANCED)
  // ============================================

  handleSearch(event) {
    this.searchQuery = event.target.value.toLowerCase().trim();
    const clearBtn = document.getElementById('clearSearch');
    
    // Show/hide clear button
    if (clearBtn) {
      clearBtn.style.display = this.searchQuery ? 'flex' : 'none';
    }

    // Filter and render
    this.renderContent();
  }

  clearSearch() {
    document.getElementById('search').value = '';
    this.searchQuery = '';
    document.getElementById('clearSearch').style.display = 'none';
    this.renderContent();
  }

  filterFilesBySearch(files) {
    if (!this.searchQuery) return files;

    return files.filter(file => {
      const name = file.name.toLowerCase();
      const path = file.path.toLowerCase();
      const type = file.type.toLowerCase();
      
      return (
        name.includes(this.searchQuery) ||
        path.includes(this.searchQuery) ||
        type.includes(this.searchQuery)
      );
    });
  }

  // ============================================
  // FILE STRUCTURE LOADING
  // ============================================

  async loadFileStructure() {
    try {
      // This would load from your data.js or API
      // For now, we'll use placeholder data
      this.allFiles = this.generatePlaceholderFiles();
      this.renderContent();
    } catch (error) {
      console.error('Error loading files:', error);
    }
  }

  generatePlaceholderFiles() {
    // This generates sample file data structure
    // Replace with actual data from your API
    return [
      {
        name: 'Arrays',
        type: 'folder',
        icon: '📁',
        badge: 'FOLDER',
        path: 'Arrays',
        children: [
          {
            name: 'Easy',
            type: 'folder',
            icon: '📁',
            badge: 'FOLDER',
            path: 'Arrays/Easy',
            children: [
              {
                name: 'Problem_1.cpp',
                type: 'cpp',
                icon: '⚙️',
                badge: 'C++',
                path: 'Arrays/Easy/Problem_1.cpp',
                size: '2.3 KB',
                modified: '2 days ago',
                solved: true
              },
              {
                name: 'Problem_2.cpp',
                type: 'cpp',
                icon: '⚙️',
                badge: 'C++',
                path: 'Arrays/Easy/Problem_2.cpp',
                size: '1.8 KB',
                modified: '1 day ago',
                solved: true
              }
            ]
          },
          {
            name: 'Medium',
            type: 'folder',
            icon: '📁',
            badge: 'FOLDER',
            path: 'Arrays/Medium',
            children: []
          }
        ]
      },
      {
        name: 'Strings',
        type: 'folder',
        icon: '📁',
        badge: 'FOLDER',
        path: 'Strings',
        children: []
      }
    ];
  }

  // ============================================
  // CARD RENDERING (ENHANCED)
  // ============================================

  renderContent() {
    const content = document.getElementById('content');
    if (!content) return;

    // Get current folder contents
    let currentItems = this.getCurrentFolderContents();
    
    // Apply search filter
    const filteredItems = this.filterFilesBySearch(currentItems);

    // Update breadcrumbs
    this.updateBreadcrumbs();

    // Clear content
    content.innerHTML = '';

    // Show no results if search returns nothing
    if (this.searchQuery && filteredItems.length === 0) {
      this.showNoResults(content);
      return;
    }

    // Show empty state if folder is empty
    if (!this.searchQuery && currentItems.length === 0) {
      this.showEmptyState(content);
      return;
    }

    // Render cards grid
    const grid = document.createElement('div');
    grid.className = 'cards-grid';

    filteredItems.forEach((file, index) => {
      const card = this.createCard(file);
      // Stagger animation
      card.style.animationDelay = `${index * 50}ms`;
      grid.appendChild(card);
    });

    content.appendChild(grid);
  }

  createCard(file) {
    const template = document.getElementById('cardTemplate');
    const card = template.content.cloneNode(true);

    const article = card.querySelector('.card');
    const icon = card.querySelector('.card-icon');
    const badge = card.querySelector('.card-badge');
    const title = card.querySelector('.card-title');
    const metaType = card.querySelector('.metadata-type');
    const metaSize = card.querySelector('.metadata-size');
    const metaDate = card.querySelector('.metadata-date');
    const openBtn = card.querySelector('.open-btn');
    const solvedDiv = card.querySelector('.solved');

    // Set data attributes
    article.dataset.path = file.path;
    article.dataset.type = file.type;

    // Icon and badge
    icon.textContent = file.icon;
    badge.textContent = file.badge;
    badge.className = `card-badge ${file.type}`;

    // Title
    title.textContent = file.name;

    // Metadata
    metaType.textContent = this.getFileTypeLabel(file.type);
    metaSize.textContent = file.size || 'N/A';
    metaDate.textContent = file.modified || 'N/A';

    // Solved indicator
    if (file.solved) {
      article.classList.add('solved');
      solvedDiv.title = 'Problem Solved';
    }

    // Click handlers
    article.addEventListener('click', () => this.selectCard(article, file));
    openBtn.addEventListener('click', (e) => {
      e.stopPropagation();
      this.openFile(file);
    });

    // Keyboard support
    article.addEventListener('keypress', (e) => {
      if (e.key === 'Enter' || e.key === ' ') {
        e.preventDefault();
        this.openFile(file);
      }
    });

    return card;
  }

  selectCard(cardElement, file) {
    // Remove previous selection
    if (this.selectedCard) {
      this.selectedCard.classList.remove('selected');
    }

    // Add selection to current card
    cardElement.classList.add('selected');
    this.selectedCard = cardElement;
  }

  openFile(file) {
    if (file.type === 'folder') {
      // Navigate into folder
      this.currentPath.push(file.name);
      this.renderContent();
    } else {
      // Open file (could show preview or navigate)
      console.log('Opening file:', file.path);
      // TODO: Implement file preview or navigation
    }
  }

  getCurrentFolderContents() {
    let current = this.allFiles;

    // Navigate through path
    for (const segment of this.currentPath) {
      const next = current.find(item => item.name === segment);
      if (next && next.children) {
        current = next.children;
      } else {
        return [];
      }
    }

    return current;
  }

  // ============================================
  // EMPTY STATES
  // ============================================

  showEmptyState(container) {
    const template = document.getElementById('emptyStateTemplate');
    const state = template.content.cloneNode(true);
    container.appendChild(state);
  }

  showNoResults(container) {
    const template = document.getElementById('noResultsTemplate');
    const state = template.content.cloneNode(true);

    // Set search term in message
    const searchTerm = state.querySelector('#searchTerm');
    if (searchTerm) {
      searchTerm.textContent = `No files matching "${this.searchQuery}"`;
    }

    // Setup clear button
    const clearBtn = state.querySelector('#clearAllSearch');
    if (clearBtn) {
      clearBtn.addEventListener('click', () => this.clearSearch());
    }

    container.appendChild(state);
  }

  // ============================================
  // BREADCRUMBS
  // ============================================

  updateBreadcrumbs() {
    const breadcrumbs = document.getElementById('breadcrumbs');
    if (!breadcrumbs) return;

    let html = '<a href="#" class="breadcrumb-link">Home</a>';

    this.currentPath.forEach((segment, index) => {
      html += ` / <a href="#" class="breadcrumb-link" data-index="${index}">${segment}</a>`;
    });

    breadcrumbs.innerHTML = html;

    // Add click handlers
    breadcrumbs.querySelectorAll('.breadcrumb-link').forEach((link, index) => {
      link.addEventListener('click', (e) => {
        e.preventDefault();
        if (index === 0) {
          // Home
          this.currentPath = [];
        } else {
          // Navigate to specific breadcrumb
          this.currentPath = this.currentPath.slice(0, index);
        }
        this.renderContent();
      });
    });
  }

  // ============================================
  // KEYBOARD NAVIGATION
  // ============================================

  handleKeyboardNav(event) {
    if (event.key === 'Escape') {
      this.clearSearch();
      document.getElementById('search')?.blur();
    }

    // Arrow key navigation between cards
    if (['ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight'].includes(event.key)) {
      event.preventDefault();
      this.navigateCards(event.key);
    }

    // Ctrl/Cmd + F to focus search
    if ((event.ctrlKey || event.metaKey) && event.key === 'f') {
      event.preventDefault();
      document.getElementById('search')?.focus();
    }
  }

  navigateCards(direction) {
    const cards = Array.from(document.querySelectorAll('.card'));
    if (cards.length === 0) return;

    const currentIndex = this.selectedCard
      ? cards.indexOf(this.selectedCard)
      : -1;

    let nextIndex = currentIndex;

    switch (direction) {
      case 'ArrowRight':
        nextIndex = Math.min(currentIndex + 1, cards.length - 1);
        break;
      case 'ArrowLeft':
        nextIndex = Math.max(currentIndex - 1, 0);
        break;
      case 'ArrowDown':
        // Assuming 4 columns, move down by 4
        nextIndex = Math.min(currentIndex + 4, cards.length - 1);
        break;
      case 'ArrowUp':
        nextIndex = Math.max(currentIndex - 4, 0);
        break;
    }

    if (nextIndex !== currentIndex) {
      cards[nextIndex]?.focus();
      cards[nextIndex]?.click();
    }
  }

  // ============================================
  // THEME MANAGEMENT
  // ============================================

  setupTheme() {
    const savedTheme = localStorage.getItem('theme') || 'light';
    this.setTheme(savedTheme);

    const themeSwitch = document.getElementById('themeSwitch');
    if (themeSwitch) {
      themeSwitch.checked = savedTheme === 'dark';
    }
  }

  toggleTheme() {
    const currentTheme = document.documentElement.getAttribute('data-theme') || 'light';
    const newTheme = currentTheme === 'light' ? 'dark' : 'light';
    this.setTheme(newTheme);
  }

  setTheme(theme) {
    document.documentElement.setAttribute('data-theme', theme);
    localStorage.setItem('theme', theme);
  }

  // ============================================
  // MOBILE SIDEBAR TOGGLE
  // ============================================

  toggleSidebar() {
    const sidebar = document.getElementById('sidebar');
    sidebar?.classList.toggle('open');
  }

  // ============================================
  // SCROLL TO TOP
  // ============================================

  setupScrollTop() {
    const button = document.getElementById('scrollTop');
    const content = document.getElementById('content');

    if (!button || !content) return;

    content.addEventListener('scroll', () => {
      if (content.scrollTop > 300) {
        button.classList.add('visible');
      } else {
        button.classList.remove('visible');
      }
    });

    button.addEventListener('click', () => {
      content.scrollTo({ top: 0, behavior: 'smooth' });
    });
  }

  // ============================================
  // UTILITY FUNCTIONS
  // ============================================

  getFileTypeLabel(type) {
    const labels = {
      'cpp': 'C++',
      'markdown': 'Markdown',
      'folder': 'Folder',
      'py': 'Python',
      'js': 'JavaScript',
    };
    return labels[type] || 'File';
  }

  formatFileSize(bytes) {
    if (bytes === 0) return '0 B';
    const k = 1024;
    const sizes = ['B', 'KB', 'MB', 'GB'];
    const i = Math.floor(Math.log(bytes) / Math.log(k));
    return Math.round(bytes / Math.pow(k, i) * 100) / 100 + ' ' + sizes[i];
  }

  getTimeAgo(date) {
    const seconds = Math.floor((new Date() - new Date(date)) / 1000);
    let interval = seconds / 31536000;

    if (interval > 1) return Math.floor(interval) + ' years ago';
    interval = seconds / 2592000;
    if (interval > 1) return Math.floor(interval) + ' months ago';
    interval = seconds / 86400;
    if (interval > 1) return Math.floor(interval) + ' days ago';
    interval = seconds / 3600;
    if (interval > 1) return Math.floor(interval) + ' hours ago';
    interval = seconds / 60;
    if (interval > 1) return Math.floor(interval) + ' minutes ago';
    return Math.floor(seconds) + ' seconds ago';
  }
}

// ============================================
// INITIALIZE APP
// ============================================

document.addEventListener('DOMContentLoaded', () => {
  new FileExplorer();
});
