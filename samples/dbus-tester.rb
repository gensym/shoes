Shoes.app :height => 600, :width => 400 do
  @activations = 0
  @invitations = 0
  @screenshots = 0
  @dbus = Shoes::SugarDBusService.instance

  @dbus.on_set_active = lambda do |active|
    @activations += 1
    draw
  end

  @dbus.on_invite = lambda do |key|
    @invitations += 1
    draw
  end

  @dbus.on_take_screenshot = lambda do ||
    @screenshots += 1
    draw
  end

  def draw
    clear do
      stack do
        para "DBus: #{@dbus}, DBus service: #{@dbus.instance_eval { @service }}"
        para "Activations: #{@activations}"
        para "Invitations: #{@invitations}"
        para "Screenshots: #{@screenshots}"
      end
    end
  end

  draw
end
